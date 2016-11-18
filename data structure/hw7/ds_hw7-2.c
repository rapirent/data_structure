#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_VERTICES 1000

struct node{
    int vertex;
    int duration;
    struct node *next;

};
typedef struct node* nodepointer;
struct headnode{
    int count;
    nodepointer link;
}graph[MAX_VERTICES];

int anti_topo[MAX_VERTICES]={0};//anti_topo_index為最上方元素的INDEX
int adj_matrix[MAX_VERTICES][MAX_VERTICES]={0};//拿來接數據
int earliest[MAX_VERTICES]={0};
int latest[MAX_VERTICES]={0};
int early_time[MAX_VERTICES]={0};
int late_time[MAX_VERTICES]={0};
int print[MAX_VERTICES][2]={0};

void ini_matrix(void);
int root_find(int x);
void tree_union(int x, int y);

int main(void)
{
    char file_location[10000]={'\0'};
    printf("Please input the file name(need .txt followed):");
    fgets(file_location,10000,stdin);
    file_location[strlen(file_location)-1]='\0';
    FILE *read=NULL;
    if((read = fopen(file_location,"r"))==NULL)
    {
        printf("the file %s does not exist!\n",file_location);
        exit(1);
    }
    int vertices_num;
    fscanf(read,"%d",&vertices_num);//讀到啦
    ini_matrix();//初始化圖
    //匯入圖
    int count_adj_row,count_adj_col,count_not_zero=-1;
    printf("receive an array:\n");
    // int temp;
    for(count_adj_row=0;count_adj_row<vertices_num;count_adj_row++)
    {
        for(count_adj_col=0;count_adj_col<vertices_num;count_adj_col++)
        {
            fscanf(read,"%d",&adj_matrix[count_adj_row][count_adj_col]);
            if(adj_matrix[count_adj_row][count_adj_col]!=0)
            {
                //從count_adj_row連出去
                graph[count_adj_col].count++;//連到[count_adj_col],故count_adj_col之先行點數目加一
                struct node* new_node=malloc(sizeof(struct node));
                new_node->vertex = count_adj_col;
                new_node->duration = adj_matrix[count_adj_row][count_adj_col];
                //從count_adj_row連到count_adj_col的邊上代表的活動所需時間
                new_node->next = NULL;
                if(graph[count_adj_row].link==NULL)
                {
                    if(new_node==NULL)
                    {
                        printf("the node can not be created!\n");
                        exit(1);
                    }
                    graph[count_adj_row].link = new_node;
                }
                else
                {
                    struct node* traversal = graph[count_adj_row].link;
                    while(traversal->next !=NULL)
                    {
                        traversal=traversal->next;
                    }
                    traversal->next= new_node;
                }
                count_not_zero++;
                print[count_not_zero][0]=count_adj_row;
                print[count_not_zero][1]=count_adj_col;
            }
            printf("%2d ",adj_matrix[count_adj_row][count_adj_col]);
        }
        printf("\n");
    }
    //find the start node
    int count_start_row,count_start_col,starter=0,temp_shu,judge=0;
    for(count_start_col=0;count_start_col<vertices_num;count_start_col++)
    {
        // temp_shu = ;
        for(count_start_row=0;count_start_row<vertices_num;count_start_row++)
        {
            if(adj_matrix[count_start_row][count_start_col]!=0)
            {
                break;
            }
        }
        if(adj_matrix[count_start_row][count_start_col]!=0&&count_start_row<vertices_num)
        {
            continue;
        }
        starter=count_start_col;
        judge++;
    }
    if(judge!=1)
    {
        printf("INPUT ERROR\n");
        exit(1);
    }
    int only_one_end_row,only_one_end_col,judge_only_one_end=0,yes=0;
    for(only_one_end_row=0;only_one_end_row<vertices_num;only_one_end_row++)
    {
        // temp_shu = ;
        yes=0;
        for(only_one_end_col=0;only_one_end_col<vertices_num;only_one_end_col++)
        {
            if(adj_matrix[only_one_end_row][only_one_end_col]!=0)
            {
                yes=1;
                break;
            }
        }
        if(yes==0)
        {
            judge_only_one_end++;
        }
    }
    if(judge_only_one_end!=1)
    {
        printf("has more than one end node!\n");
        exit(1);
    }
    printf("the start node is %d\n",starter);

    int top=-1;//early time stack
    int i,j,k;
    struct node* traversal_node;
    int anti_topo_index=-1;
    //計算ee
    for(i=0;i<vertices_num;i++)
    {
        if(graph[i].count==0)
        {
            graph[i].count=top;
            top=i;
        }
    }
    for(i=0;i<vertices_num;i++)
    {
        if(top==-1)
        {
            printf("the input's graph has a cycle!");
            exit(1);
        }
        else
        {
            j=top;//pop from early stack
            anti_topo_index++;
            anti_topo[anti_topo_index]=j;
            top = graph[top].count;
            for(traversal_node=graph[j].link;traversal_node!=NULL;traversal_node=traversal_node->next)
            {
                k= traversal_node->vertex;
                if(earliest[k] < earliest[j] + traversal_node->duration)
                {
                    earliest[k] = earliest[j] + traversal_node->duration;
                }
                graph[k].count--;
                if(graph[k].count==0)
                {
                    graph[k].count = top;
                    top = k;
                }
            }
        }
    }
    //計算le
    int pop_count=0;
    int temp=anti_topo[anti_topo_index];//pop出來
    anti_topo_index--;
    latest[temp] = earliest[temp];
    int compare_count;
    struct node * traversal_anti_topo = NULL;
    int compare_shu;//比最小出來
    for(pop_count=0;pop_count<vertices_num-1;pop_count++)
    {
        temp = anti_topo[anti_topo_index];//pop出來
        anti_topo_index--;
        traversal_anti_topo = graph[temp].link;
        compare_shu = latest[traversal_anti_topo->vertex] - (traversal_anti_topo->duration);
        while(traversal_anti_topo!=NULL)
        {
            if(compare_shu >=(latest[traversal_anti_topo->vertex] - (traversal_anti_topo->duration)))//發現比自己小的
            {
                compare_shu = latest[traversal_anti_topo->vertex] - (traversal_anti_topo->duration);
            }
            traversal_anti_topo = traversal_anti_topo->next;
        }
        latest[temp]=compare_shu;
    }
    printf("activity   early time  late time slack\n");
    printf("           e           l         l-e  \n    ");
    printf("\n");
    //計算 l 和 e
    int count_late_early;
    for(count_late_early=0;count_late_early<=count_not_zero;count_late_early++)
    {

        early_time[count_late_early] = earliest[print[count_late_early][0]];
        late_time[count_late_early] = latest[print[count_late_early][1]]-adj_matrix[print[count_late_early][0]][print[count_late_early][1]];
        printf("(%d,%d)  %10d%10d%10d\n",print[count_late_early][0],print[count_late_early][1],early_time[count_late_early],late_time[count_late_early],late_time[count_late_early]-early_time[count_late_early]);
    }
    fclose(read);
    return 0;
}


void ini_matrix()
{
    int count=0;
    int count2;
    for(;count<MAX_VERTICES;count++)
    {
        for(count2=0;count2<MAX_VERTICES;count2++)
        {
            adj_matrix[count][count2]=-1;
        }
        //TODO 憑感覺寫 不確定
        graph[count].count=0;
        graph[count].link = NULL;
        anti_topo[count]=-1;
        earliest[count]=0;
        latest[count]=-0;
    }
}