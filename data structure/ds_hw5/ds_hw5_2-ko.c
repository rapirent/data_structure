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
    int list_len;//list_len
    struct tree* node_list[MAX_TREE];//為何不能用MAX_TREE??
};
typedef struct tree* tree_pointer;

struct list
{
    tree_pointer key_tree;
    struct list* next;
};
typedef struct list* tree_list;

int parent[MAX_TREE]={0};//the element will not be zero
int max_flag=0;
/***************************************************/
tree_list attach_search_list(tree_list *starter,int k);//find the element in tree_list's tree node,retrun this tree_list
void attach(tree_pointer *root,tree_pointer node);//attch one tree to another
tree_pointer attach_search_node(tree_list *list_node,int k);//find teh element in specific tree_list's tree node,return node
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
    while(scanf("%s",input)!=EOF)
    {
        temp=strtok(input,blank);
        if(input[0]=='E')
        {
            //level_order(root);

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
    int count_for_clean;
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
            if(set_a>set_b)//set_b should be set_a's root
            {
                root=attach_search(&starter,set_b);
                root_shu=set_b;
                child=attach_search(&starter,set_a);
                child_shu=set_a;
            }
            else if(set_a<set_b)//set_a should be set_a's root
            {
                root=attach_search(&starter,set_a);
                root_shu=set_a;
                child=attach_search(&starter,set_b);
                child_shu=set_b;
            }
            else
            {
                pirntf("your inputs are ilegal, do not enter the same number!");
            }
            ////////////////////////////////
            if(root==child)//the same set
            {
                printf("this set is already exist!");
            }
            else
            {
                tree_list temp=starter;
                attacher=attach_search_node(&child,child_shu);//find the specific node which attached to root
                be_attached=attach_search_node(&root,root_shu);//find the specific node which was attached


            }
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

void attach(tree_pointer *root,tree_pointer node)//attch one tree to another
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

void clean(tree_pointer node[])
{
    int count_for_clean=0;
    while(count_for_clean<MAX_TREE)
    {
        node[count_for_clean]=NULL;//initialize the node
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