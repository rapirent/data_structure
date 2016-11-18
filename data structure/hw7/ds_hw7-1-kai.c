#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MCST 1000



// int selected_edges[MCST]={0};//因為不會有0邊

int adj_matrix[MCST][MCST]={0};//拿來接數據
int forest[MCST]={0};//以disjoint set 來儲存子樹
struct
{
    int node1;
    int node2;
    int length;
}edges[MCST];
int selected[MCST]={0};
int minimum_link[MCST]={0};
int minimum_length[MCST]={0};//紀錄每顆子樹的最小聯外邊index = selected的index

void ini_matrix(void);
int root_find(int x);
void tree_union(int x, int y);

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
            if(adj_matrix[count_adj_row][count_adj_col]!=0)
            {
                edges[edges_num].node1=count_adj_row;
                edges[edges_num].node2=count_adj_col;
                edges[edges_num].length=adj_matrix[count_adj_row][count_adj_col];
                edges_num++;
            }
        }
        printf("\n");
        //一開始的子樹全都是node
        forest[count_adj_row]=count_adj_row;//每個子樹
    }
    ///////////////////////////////
    //  0 1 2 3 4 5 6 7
    //0 0 0 0 5 0 1 2 8
    //1 ...
    //2 ...
    //代表0(1)連到3(4) 5(6) 6(7) 7(8)
    int scan_row,scan_col,smallest;
    int selected_col,num=0,selected_num=0;;
    for(scan_row=0;scan_row<vertices_num;scan_row++)
    {
        smallest=999;
        for(scan_col=0;scan_col<vertices_num;scan_col++)
        {
            if(adj_matrix[count_adj_row][count_adj_col]!=0)
            {
                if(smallest>adj_matrix[count_adj_row][count_adj_col])
                {
                    smallest=adj_matrix[count_adj_row][count_adj_col];
                    selected_num=num;
                    selected_col=count_adj_col;//連到誰~
                }
                num++;
            }
        }
        selected[selected_num]=1;//被選到啦!
        //把選到邊接到的vertex(selected_col)加進union
        tree_union(scan_row,selected_col);
    }
    //開始尋找各個forest tree的最小聯外邊
    int scan_node=0,scan_tree;
    int start,end;
    while(judge_tree_num(vertices_num)!=0)
    {
        scan_node=0;
        while(scan_node<vertices_num)
        {
            if(selected[scan_node]==0)//沒有被選到~
            {
                start=edges[scan_node].node1;
                end=edges[scan_node].node2;
                if(forest[start]!=forest[end])//這個邊不會是cycle
                {
                    if(minimum_length[start]>edges[scan_node].length)//start的子樹聯外邊,判斷最小,留最小
                    {
                        minimum_length[start]=edges[scan_node].length;
                        minimum_link[start]=scan_node;
                    }
                    if(minimum_length[end]>edges[scan_node].length)//end的子樹聯外邊,判斷最小,留最小
                    {
                        minimum_length[end]=edges[scan_node].length;
                        minimum_link[end]=scan_node;
                    }
                }
            }
            scan_node++;
        }
        //把選到的最小邊連外邊union起來
        for(scan_tree=0;scan_tree<=edges_num;scan_tree++)
        {
            if(minimum_link[scan_tree]!=0)
            {
                tree_union(scan_tree,root_find(minimum_link[end]));
                selected[minimum_link[scan_tree]]=1;
            }
        }
    }
    int print_node;
    for(print_node=0;print_node<=edges_num;print_node++)
    {
        if(selected[print_node]!=0)
        {
            printf("(%d,%d,)=%d\n",edges[print_node].node1,edges[print_node].node2,edges[print_node].length);
        }
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
        forest[count]=-1;
        minimum_length[count]=999;
    }
}
int root_find(int x)
{
    return (x == forest[x]) ? x : /*(forest[x] = */root_find(forest[x]);//);
}
void tree_union(int x, int y)//將x加到y
{
    forest[root_find(x)] = root_find(y);
}
int judge_tree_num(int x)
{
    int count=0;
    int temp = forest[0];
    while(count<x)
    {
        if(forest[count]!=temp)
        {
            return 1;//還有殘留
        }
        count++;
    }
    return 0;//只剩下一顆子樹了
}