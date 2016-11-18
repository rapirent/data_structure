/****************************************
author:tony_ding
title:ds_hw5_2
****************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_TREE 1000
/****************************************************/
struct tree
{
    int key;//key
    int list_len;//store the number of next level node's quantity
    struct tree* node_list[MAX_TREE];
};
typedef struct tree* tree_pointer;

struct list
{
    tree_pointer key_tree_pointer;
    struct list* next;
};
typedef struct list* tree_list;

int parent[MAX_TREE]={0};//the element will not be zero
/***************************************************/
void insert(tree_pointer *node,int k);
tree_list create_tree(void);
/***************************************************/
void insert(tree_list *starter,int key);//insert a tree_list node with one tree node
/***************************************************/
void weighted_union(int i,int j);
/***************************************************/
void level_order(tree_pointer *root);
int level_order_search(tree_pointer node);

int main(void)
{
    char input[10000]={'\0'};
    char *blank = " ";//to cut the string
    char *equal = "=";
    char *temp;//cutted string
    tree_list starter=NULL;
    tree_pointer node=NULL;
    int input_shu;
    int input_max;
    while(scanf("%s",input)!=EOF)
    {
        temp=strtok(input,blank);
        if(input[0]=='E')
        {
            //level_order(root);
            tree_list starter=NULL;
            starter=create_tree();
            return 0;
        }
        else if(input[0]=='S')
        {
            //Set
            break;
        }
        else
        {
            input_shu=atoi(temp);
            parent[input_shu]=-1;
            printf("shu=%d\n",input_shu);
            while((temp = strtok(NULL,blank)))
            {
                input_shu=atoi(temp);
                parent[input_shu]=-1;
                printf("shu=%d\n",input_shu);
            }
            //insert
        }

    }
    int count_for_clean=0;
    while(input[count_for_clean]!='\0')//clean the input , because we will use strlen function
    {
        input[count_for_clean]='\0';
        count_for_clean++;
    }
    int set_a,set_b,child_shu,root_shu;
    tree_list root,child;
    tree_pointer attacher=NULL,be_attached=NULL;
    while(scanf("%s",input)!=EOF&&input[strlen(input)-1]!='\n')
    {
        printf("a\n");
        temp=strtok(input,equal);
        if(input[0]=='E')
        {
            //level_order
            return 0;
        }
        else
        {
            set_a=atoi(temp);
            printf("shu1=%d\n",set_a);
            temp=strtok(NULL,equal);
            set_b=atoi(temp);
            printf("shu2=%d\n",set_b);
            weighted_union(set_a,set_b);
        }
        //清空input
        count_for_clean=0;
        while(input[count_for_clean]!='\0')
        {
            input[count_for_clean]='\0';
            count_for_clean++;
        }
    }
    return 0;
}

tree_list create_tree()
{
    int traversal=0;
    tree_list list_node = NULL,starter = NULL;
    for(traversal=1;parent[traversal]!=0;traversal++)
    {
        if(parent[traversal]<0)
        {
            tree_pointer tree_node = (tree_pointer)malloc(sizeof(struct tree));
            tree_node->key = traversal;
            tree_node->list_len=0;
            if(list_node==NULL)//this list_node will be the first one(starter)
            {
                list_node = (tree_list)malloc(sizeof(struct list));
                list_node->key_tree_pointer= tree_node;
                list_node->next=NULL;
                starter = list_node;
            }
            else
            {
                list_node->next = (tree_list)malloc(sizeof(struct list));
                list_node=list_node->next;
                list_node->key_tree_pointer= tree_node;
                list_node->next=NULL;
            }
        }
        else
        {
            attach(parent[traversal],traversal,&starter);
        }
    }
    tree_list root=(tree_list)malloc(sizeof(struct list));

}

void attach(int parent_num,int child_num,tree_list *starter)
{

}



void insert(tree_list *starter,int key)
{
    tree_pointer temp=(tree_pointer)malloc(sizeof(struct tree));
    temp->key=key;
    temp->list_len=0;
    //void clean(temp->node_list);
    int count_for_clean=0;
    while(count_for_clean<MAX_TREE)
    {
        temp->node_list[count_for_clean]=NULL;//initialize the node_list;
    }
    if(starter==NULL)//list is empty
    {
        starter=(tree_list)malloc(sizeof(struct list));
        starter->key_tree=temp;
        starter->next=NULL;
        return ;
    }
    tree_list node = starter;
    while(1)
    {
        node=node->next;
        if(node==NULL)
        {
            node=(tree_list)malloc(sizeof(struct list))
            node->key_tree=temp;
            node->next=NULL;
            return ;
        }
    }
}
/***************************************************/
void weighted_union(int i,int j)
{
    int temp = parent[i]+parent[j];
    if(parent[i]>parent[j])//they are both negative=>j nodes > i nodes
    {
        parnet[i]=j;
        parent[j]=temp;
    }
    else if(parent[i]<parent[i])
    {
        parent[j]=i;
        parnet[i]=temp;
    }
    else
    {
        pirntf("your inputs are ilegal, do not enter the same number!\n");
        exit(1);
    }
}
/***************************************************/
void level_order(tree_pointer *root);
int level_order_search(tree_pointer node);
tree_pointer get_del(tree_pointer del_parent,int k);