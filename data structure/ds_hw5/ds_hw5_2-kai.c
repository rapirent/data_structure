/****************************************
author:tony_ding
title:ds_hw5_2
****************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_TREE 1000
/****************************************************/
int parent[MAX_TREE]={0};//共有三種模式,-1=初始未被使用 >=0:元素

struct tree
{
    int key;//key
    int list_len;//list_len
    int level;
    struct tree* node_list[MAX_TREE];
};
typedef struct tree* tree_pointer;

void tree_union(int a,int b);
tree_pointer array_to_struct(int root,int max);
void level_order(tree_pointer *root);
int find_root(int leaf);

int main(void)
{
    char input[10000]={'\0'};//to receive the input
    char *temp=NULL;
    int num;
    int count_initial=0;
    int max_num=-1;//record the max tree's index=content
    for(count_initial=0;count_initial<1000;count_initial++)
    {
        parent[count_initial]=-1;
    }
    while(scanf("%s",input)!=EOF)
    {
        temp=strtok(input," ");
        if(input[0]=='E')
        {
            //print
            int count_search;
            tree_pointer root;
            for(count_search=0;count_search<=max_num;count_search++)
            {
                if(parent[count_search]==count_search)
                {
                    root=array_to_struct(count_search,max_num);
                    level_order(&root);
                }
            }
            printf("test\n");
            for(count_search=0;count_search<=max_num;count_search++)
            {
                printf("parnet[%d]=%d\n",count_search,parent[count_search]);
            }
            return 0;
            return 0;
        }
        else if(input[0]=='S')
        {
            //go to next input process
            break;
        }
        else
        {
            num=atoi(temp);
            parent[num]=num;
            if(num>max_num)
            {
                max_num=num;
            }
            printf("num=%d\n",num);
            while(temp=strtok(NULL," "))//if token was not found, return NULL value
            {
                num=atoi(temp);
                parent[num]=num;
                if(num>max_num)
                {
                    max_num=num;
                }
                printf("num=%d\n",num);
            }

        }
    }
    int num_a,num_b;
    tree_pointer root=NULL;
    while(scanf("%s",input)!=EOF&&input[strlen(input)-1]!='\n')//because the last char is '\n'
    {
        temp=strtok(input,"=");
        if(input[0]=='E')
        {
            //print
            int count_search;
            tree_pointer root;
            for(count_search=0;count_search<=max_num;count_search++)
            {
                if(parent[count_search]==count_search)
                {
                    root=array_to_struct(count_search,max_num);
                    level_order(&root);
                    printf("\n");
                }
            }
            printf("test\n");
            for(count_search=0;count_search<=max_num;count_search++)
            {
                printf("parnet[%d]=%d\n",count_search,parent[count_search]);
            }
            return 0;
        }
        else
        {
            num_a=atoi(temp);
            printf("num_a=%d\n",num_a);
            temp=strtok(NULL,"=");
            num_b=atoi(temp);
            printf("num_2=%d\n",num_b);
            tree_union(num_a,num_b);
        }
    }
}
void tree_union(int leaf_a,int leaf_b)
{
    int root_a,root_b;
    root_a=find_root(leaf_a);
    root_b=find_root(leaf_b);
    if(root_a>root_b)//b will be the root
    {
        parent[root_a]=root_b;
    }
    else if(root_a<root_b)//a will be the root
    {
        parent[root_b]=root_a;
    }
    else
    {
        printf("you can not enter two leaf nodes which have same root!(same group)\n");
        exit(1);
    }
}
int find_root(int leaf)
{
    if(parent[leaf]!=leaf)
    {
        return find_root(parent[leaf]);//still child
    }
    return leaf;//root
}
tree_pointer array_to_struct(int root,int max)
{
    int count_search;
    tree_pointer queue[MAX_TREE];
    int count_clean;
    for(count_clean=0;count_clean<MAX_TREE;count_clean++)
    {
        queue[count_clean]=NULL;
    }
    int rear,front;
    rear=front=-1;
    tree_pointer tree_root=NULL,tree_parent=NULL;
    tree_root=(tree_pointer)malloc(sizeof(struct tree));
    tree_root->key=root;
    tree_root->list_len=0;
    tree_root->level=0;//root at 0 level
    rear++;
    queue[rear]=tree_root;
    while(1)
    {
        child_exist=0;
        front++;
        if(queue[front]==NULL)
        {
            break;

        }
        tree_parent=queue[front];
        queue[front]=NULL;
        for(count_search=0;count_search<=max;count_search++)
        {
            if((parent[count_search]==tree_parent->key)&&(parent[count_search]!=count_search))//find the child
            {
                rear++;
                queue[rear]=(tree_pointer)malloc(sizeof(struct tree));
                queue[rear]->key=count_search;
                queue[rear]->list_len=0;
                queue[rear]->level=((tree_parent->level)+1);
                tree_parent->node_list[tree_parent->list_len]=queue[rear];
                tree_parent->list_len++;
                //free(queue[rear]);
            }
        }
    }
    return tree_root;
}

void level_order(tree_pointer *root)
{
    tree_pointer traversal_queue[MAX_TREE]={NULL};
    tree_pointer ptr=NULL;
    int front,rear;
    front=rear=-1;
    if(*root==NULL)
    {
        printf("this tree is empty!\n");
        return;
    }
    front++;
    traversal_queue[front]=*root;
    int level_tag;//to distinguish the different level
    printf("{");
    int level_temp;//保留上一層的level
    while(1)
    {
        rear++;
        ptr=traversal_queue[rear];
        traversal_queue[rear]=NULL;
        if(ptr!=NULL)
        {
            if(ptr->level==0)//為root
            {
                if(ptr->list_len!=0)//不只有一個節點
                {
                    printf("{%d",ptr->key);
                }
                else
                {
                    printf("%d",ptr->key);
                }
                level_temp=0;
            }
            else
            {
                if(ptr->level!=level_temp)//為該層第一個!
                {
                    printf("},{");
                    printf("%d",ptr->key);
                    level_temp=ptr->level;
                }
                else
                {
                    printf(",%d",ptr->key);
                }
            }
            while(ptr->list_len>0)
            {
                front++;
                traversal_queue[front]=ptr->node_list[ptr->list_len-1];
                ptr->list_len--;
            }
            if(traversal_queue[rear+1]==NULL&&ptr->level!=0)//ptr不是root
            {
                printf("}");
            }
        }
        else
        {
            printf("}");
            break;
        }
    }
}