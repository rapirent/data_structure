#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MCST 1000

struct
{
    int node1;
    int node2;
    int length;
}selected_edge[MCST];

// int selected_edges[MCST]={0};//因為不會有0邊

int adj_matrix[MCST][MCST]={0};//拿來接數據
int forest_union[MCST]={0};




int main(void)
{
    char file_location[10000]={'\0'};
    printf("Please input the file name(need .txt followed):");
    scanf("%s",file_location);
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
    int count_adj_row,count_adj_col;
    printf("收到一個陣列:\n");
    int edge_list_index=0,temp;
    for(count_adj_row=0;count_adj_row<vertices_num;count_adj_row++)
    {
        for(count_adj_col=0;count_adj_col<vertices_num;count_adj_col++)
        {
            fscanf(read,"%d",&temp);

            //TODO
            if(temp]<0)
            {
                printf("input error, the input element < 0\n");
                exit(1);
            }
            if(count_adj_col>=count_adj_row)
            {
                adj_matrix[count_adj_row][count_adj_col]=temp;
            }
            //
            printf("%d ",adj_matrix[count_adj_row][count_adj_col]);
        }
        printf("\n");
        //一開始的子樹全都是node
        forest_union[count_adj_row]=count_adj_row;
    }
    int selected_edges_index=0;
    while(selected_edges_index<(num-1))
    {
        int min,select_row,select_col;
        int search_length;
        int count_row=0;
        int count_col=0;
        for(count_row=0;count_row<num;count_row++)
        {
            for(count_col=0;count_col<num;count_col++)
            {
                if(adj_matrix[count_row][count_col]>0&&(root_find(count_row)!=root_find(count_col))
                {
                    min=adj_matrix[count_row][count_col];
                    select_row=count_row;
                    select_col=count_col;
                }
            }
        }
        selected_edge[selected_edges_index].length=min;
        selected_edge[selected_edges_index].node1 = select_row;
        selectde_edge[selected_edges_index].node2 = select_col;
        adj_matrix[select_row][select_col]=-1;
        //待修改,憑感覺寫的
        union(select_row,select_col);
        selected_edges_index++;
    }
    int count_num=0,count_print;
    int print_now=selected_edge[0].length,print_now_index=0;
    for(;count_num<num;count++)
    {
        for(count_print=0;count_print<(num-count_num);count_print++)
        {
            if(selected_edge[count_print].length<print_now&&selected_edge[count_print].length!=-1)
            {
                print_now=selected_edge[count_print].length;
                print_now_index=count_print;
            }
        }
        print("(%d,%d)=%d\n",print_now,selected_edge[print_now_index].node1,selected_edge[print_now_index].node2);
        selected_edge[print_now_index].length=-1;
    }
    return 0;
}

int is_cycle(int value){
    int i;
    for(i=0;i<num;i++)
    {
        if(a[i]==1 && i==value) return 1;
    }
    return 0;
}



void ini_matrix()
{
    int count=0;
    int count2;
    for(;count<MCST;count++)
    {
        for(count2=0;count2<MCST;count2++)
        {
            adj_matrix[count][count2]=-1;
        }
        forest_union[count]=-1;
    }
}

int root_find(int x)
{
    return (x == forest_union[x]) ? x : (forest_union[x] = root_find(forest_union[x]));
}
void union(int x, int y)//將x加到y
{
    forest_union[root_find(x)] = root_find(y);
}