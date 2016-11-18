#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX_TREE 1000

int tree[MAX_TREE];
/************************/
void initial();
void insert(int key);
void del(int key);
/************************/
int main(void){
    char input[10000]={'\0'};
    char *blank = " ";
    char *temp;
    tree_pointer root=NULL;
    int first_blank=1;
    int now_shu_degree=0;
    int input_shu;
    while(scanf("%s",input)!=EOF)
    {
        temp=strtok(input,blank);
        if(input[0]=='E')
        {
            //level_order(root);
            return 0;
        }
        else if(input[0]=='D')
        {
            //delete
            break;
        }
        else
        {
            input_shu=atoi(temp);
            insert(&root,input_shu);
            printf("shu=%d\n",input_shu);
            while((temp = strtok(NULL,blank)))
            {
                input_shu=atoi(temp);
                insert(&root,input_shu);
                printf("shu=%d\n",input_shu);
            }
            //insert
        }

    }
    while(scanf("%s",input)!=EOF)
    {
        printf("a\n");
        temp=strtok(input,blank);
        if(input[0]=='E')
        {
            level_order(&root);
            return 0;
        }
        else
        {
            input_shu=atoi(temp);
            printf("shu=%d\n",input_shu);
            delTree(&root,input_shu);
            while((temp = strtok(NULL,blank)))
            {
                input_shu=atoi(temp);
                delTree(&root,input_shu);
                printf("shu=%d\n",input_shu);
            }
        }
    }
    return 0;
}
void initial()
{
    int count=0;
    for(;count<MAX_TREE;count++)
    {
        tree[count]=-1;
    }
}
void insert(int key)
{
    int insert_index=insert_search(key);//get the insert place
    if(insert_index!=0)
    {
        if(insert_index==1)//if tree is empty
        {
            tree[1]=key;
            if(k>temp->key)
            {
                temp->right_child=ptr;//greater than key, so insert at his right
            }
            else
            {
                temp->left_child = ptr;
                printf("TEST\n");
            }
        }
        else
        {
            if(key>tree[index])
            {
                tree[index*2+1]=key;//greater than key, so insert at his right
            }
            else
            {
                tree[index*2]=key;
            }
        }
    }
    else
    {
        printf("the node can not be added!\n");
    }
}
int insert_search(int key)
{
    if(tree[1]==-1)//tree is empty
    {
        return 1;
    }
    int index=1;
    while(tree[index]!=-1)
    {
        if(key==tree[index])
        {
            return 0;//find it
        }
        if(key>tree[index])
        {
            index=index*2;//go to right
        }
        else
        {
            index=index*2+1;
        }
    }
    return index;
}

void del(int key)
{
    int del_index=del_search(key);//find the deleted element's parent , if element is root, then temp_parent==temp
    if(del_index==0)
    {
        printf("the tree can not be deleted!\n");
        return ;
    }

    //delete the leaf node
    if(tree[2*del_index]==-1&&tree[2*del_index+1]==NULL)
    {
        tree[del_index]=-1;
        return ;
    }
    //there is no left tree at deleted node
    if(tree[2*del_index]==-1)
    {
        if(del_index==1)//deleted element is root
        {
            for(;;)
            return ;
        }
        else if(del_parent->left_child==del)//deleted element is his'parent's left child
        {
            del_parent->left_child=del->right_child;
            free(del);
            del=NULL;
            return ;
        }
        else if(del_parent->right_child==del)//deleted element is his parent's right child
        {
            del_parent->right_child=del->right_child;
            free(del);
            //del=NULL;
            return ;
        }
    }
    //no right tree at deleted node
    if(del->right_child==NULL)
    {
        if(del_parent==del)//deleted element is root
        {
            del->key=(del->left_child)->key;//del's left child replace the root
            ptr_left=(del->left_child)->left_child;
            ptr_right=(del->left_child)->right_child;
            free(del->left_child);//deleted the former del's left child
            del->left_child=NULL;
            del->left_child=ptr_left;//link teh root to former (del's left child)'s child
            del->right_child=ptr_right;
            return ;
        }
        else if(del_parent->left_child==del)//deleted element is his'parent's left child
        {
            del_parent->left_child=del->left_child;
            free(del);
            del=NULL;
            return ;
        }
        else if(del_parent->right_child==del)//deleted element is his parent's right child
        {
            del_parent->left_child=del->left_child;
            free(del);
            return ;
        }
    }
    //deleted node has two child
    if(del->right_child!=NULL&&del->left_child!=NULL)
    {
        ptr_left=del->left_child;
        ptr_right=del->right_child;
        while((ptr_left->right_child)!=NULL)
        {
            ptr_left=ptr_left->right_child;
        }
        //now the ptr_left is best num among del's left tree
        del->key=ptr_left->key;
        free(ptr_left);//deleted former left child's node
        ptr_left=NULL;
    }
}

int del_search(int key)
{
    tree_pointer temp = node;
    if(tree[1]==-1)//tree is empty
    {
        return 0;
    }
    int index=1
    while(tree[index]!=-1)//it is not in this tree(reach leaf)
    {
        if(key==tree[index])//find it !
        {
            return index; //return the deleted element's parents or root node(first round)
        }
        if(key>tree[index])// k is greater than this nood
        {
            index=index*2+1;//go to right
        }
        else
        {
            index=index*2;//go to left
        }
        //now temp is possible to be the leaf
    }
    return 0;//not find
}