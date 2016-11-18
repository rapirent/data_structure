#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MCST 1000



// int selected_edges[MCST]={0};//因為不會有0邊

int adj_matrix[MCST][MCST]={0};//拿來接數據
int forest[MCST]={0};//以disjoint set 來儲存子樹
struct
{
    int node1;//start起點
    int node2;//end終點
    int length;//他的權重
}edges[MCST];
int minimum_link[MCST]={0};
int minimum_link_length[MCST]={0};//紀錄每顆子樹的最小聯外邊index = selected的index
int selected[MCST]={0};//順序印出來!
int print_sort[MCST]={0};//由大而小印出來使用

void ini_matrix(void);//初始化所有
int root_find(int x);
void tree_union(int x, int y);
void ini_minimum(void);


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
    printf("receive an array:\n");
    int edge_list_index=0,edges_num=0;
    for(count_adj_row=0;count_adj_row<vertices_num;count_adj_row++)
    {
        for(count_adj_col=0;count_adj_col<vertices_num;count_adj_col++)
        {
            fscanf(read,"%d",&adj_matrix[count_adj_row][count_adj_col]);
            //TODO
            if(adj_matrix[count_adj_row][count_adj_col]<0)
            {
                printf("input error, the input element < 0\n");
                exit(1);
            }
            printf("%2d ",adj_matrix[count_adj_row][count_adj_col]);
            if(adj_matrix[count_adj_row][count_adj_col]!=0)//儲存邊
            {
                edges[edges_num].node1=count_adj_row;
                edges[edges_num].node2=count_adj_col;
                edges[edges_num].length=adj_matrix[count_adj_row][count_adj_col];
                edges_num++;
            }
        }
        printf("\n");
        //一開始的子樹全都是node,初始化disjoint
        forest[count_adj_row]=count_adj_row;//每個子樹
    }
    ///////////////////////////////
    //  0 1 2 3 4 5 6 7
    //0 0 0 0 5 0 1 2 8
    //1 ...
    //2 ...
    //代表0(1)連到3(4) 5(6) 6(7) 7(8)
    int scan_node=0,scan_tree;
    int start,end,weight;
    int count_scan;
    int count_create;
    int index;
    while(judge_tree_num(vertices_num)!=1)//做到只剩下一顆子樹
    {
        ini_minimum();
        //尋找最小連外邊
        for(count_scan=0;count_scan<edges_num;count_scan++)//edges_num=有幾個edge
        {
            start=edges[count_scan].node1;//起點
            end=edges[count_scan].node2;//終點
            weight=edges[count_scan].length;
            if(root_find(start)!=root_find(end))//兩點不屬於同一棵樹,故不會形成cycle
            {
                if((weight<minimum_link_length[root_find(start)])||(weight==minimum_link_length[root_find(start)]&&count_scan<minimum_link[root_find(start)]))
                {
                    //找到起點樹權重最小的邊,或是權重一樣的邊
                    minimum_link_length[root_find(start)] = weight;//紀錄長度
                    minimum_link[root_find(start)] = count_scan;//紀錄index
                }
                if((weight<minimum_link_length[root_find(end)])||(weight==minimum_link_length[root_find(end)]&&count_scan<minimum_link[root_find(end)]))
                {
                    //找到終點樹權重最小的邊,或是權重一樣的邊
                    minimum_link_length[root_find(end)] = weight;//紀錄長度
                    minimum_link[root_find(end)] = count_scan;//紀錄index
                }
                //不必擔心重複,因為root值一樣會被忽略,一定只有一個方向被選到
            }
        }
        //讓生成樹長大
        for(count_create=0;count_create<vertices_num;count_create++)
        {
            if(minimum_link_length[count_create]!=999)//最小聯外邊
            {
                index=minimum_link[count_create];//取得該最小聯外邊index
                tree_union(edges[index].node1,edges[index].node2);//加進去~
                selected[index]=1;
            }
        }
    }
    int print_node;
    for(print_node=0;print_node<edges_num;print_node++)
    {
        if(selected[print_node]!=0)
        {
            printf("(%d,%d)=%d\n",edges[print_node].node1+1,edges[print_node].node2+1,edges[print_node].length);
            //加一因為原本的0為1的意思
        }
    }
    return 0;
}

void ini_matrix(void)
{
    int count=0;
    int count2;
    for(;count<MCST;count++)
    {
        for(count2=0;count2<MCST;count2++)
        {
            adj_matrix[count][count2]=-1;
        }
        forest[count]=-1;
    }
}
void ini_minimum(void)
{
    int count=0;
    for(;count<MCST;count++)
    {
        minimum_link_length[count]=999;
    }
}
int root_find(int x)
{
    if(x==forest[x])
    {
        return x;
    }
    else
    {
        return root_find(forest[x]);//順便collapse
    }
}
void tree_union(int x, int y)//將x加到y
{
    forest[root_find(x)] = root_find(y);
}
int judge_tree_num(int x)
{
    int count=0;
    int temp = root_find(forest[0]);
    while(count<x)
    {
        if(root_find(forest[count])!=temp)
        {
            return 0;//還有殘留
        }
        count++;
    }
    return 1;//只剩下一顆子樹了
}