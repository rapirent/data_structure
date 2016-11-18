#include<stdlib.h>
#include<stdio.h>
#define MAX_TREE 1000

struct tree{
	int key;//key
	int num;//level num
	struct tree *right_child;
	struct tree *left_child;
};
typedef struct tree* tree_pointer;

void insert(tree_pointer *node,int key);
tree_pointer insert_search(tree_pointer node,int k);
/**********************************************************/
void delTree(tree_pointer *root,int key);
tree_pointer del_search(tree_pointer nood,int k);
/**********************************************************/
void level_order(tree_pointer);
void level_order_add(tree_pointer queue[],tree_pointer node,int *rear);
tree_pointer level_order_del(tree_pointer queue[],int *front,int *rear);

int main(void){
	char input;
 	char temp[2]={'\0'};
	tree_pointer root=NULL;
	insert(&root,3);
	insert(&root,6);
	insert(&root,2);
	printf("%d\n",root->key);
	printf("%d\n",((root->right_child)->key));
	printf("%d\n",((root->left_child)->key));
	delTree(&root,6);
    //printf("%d\n",((root->right_child)->key));
    if(root->right_child==NULL) printf("yeah!");
    else if(root->left_child==NULL) printf("no!");
    //printf("%p\n",&(root->right_child));
    /*
	while(scanf("%c",&input)!=EOF&&input!='D'&&input!='E')//ASCII code for D is 68, for E is 48
	{
		//insert/
		temp[0]=input;
		insert(&root,atoi(temp));
	}
	if(input=='D')
	{
		while(scanf("%c",&input)!=EOF&&input!='E')
		{
			//del
   			temp[0]=input;
			delTree(&root,atoi(temp));
		}
	}
	else
	{
		printf("%d",&root->key);
		//level_order(root);
	}*/
	return 0;
}

void insert(tree_pointer *node,int k)//node's type is tree** , pointer's pointer
{
	tree_pointer ptr=NULL,temp=NULL;
	temp=insert_search(*node,k);//now temp is the final node of the tree
	if(temp||(!(*node)))//if temp==0&&(*node)!=0, so there is already an element in tree
	{
		ptr = (tree_pointer)malloc(sizeof(struct tree)); // allocate the space to ptr
		ptr->key=k;//ptr restore the key
		ptr->left_child=NULL;
		ptr->right_child=NULL;
		if(*node)//if tree is not empty
		{
			if(k>temp->key)
			{
				temp->right_child=ptr;//greater than key, so insert at his right
			}
			else
			{
				temp->left_child = ptr;
			}
		}
		else//insert in an empty tree
		{
			*node=ptr;
		}
	}
}

tree_pointer insert_search(tree_pointer node,int k)//find the final node
{
    tree_pointer temp = node;
	if(!node)//this tree is empty
	{
		return NULL;//it can be added
	}
	while(temp)//if the temp reach leaf
	{
		if(k==temp->key)//find it !
		{
			return NULL;//it can't be added!
		}
        node=temp;//so node is the parent of temp,temp can use to test if it reach te leaf of the tree!
		if(k>(temp->key))//greater than key , go to right
		{
			temp=temp->right_child;
		}
		else//go to left
		{
			temp=temp->left_child;
		}
	}
	return node;//return the leaf's parent!
}

void delTree(tree_pointer *root,int k)
{
	tree_pointer ptr_right=NULL,ptr_left=NULL,del=NULL,del_parent=NULL;
	del_parent=del_search(*root,k);//find the deleted element's parent , if element is root, then temp_parent==temp
    if(!del_parent)
    {
        printf("the tree can not be deleted!\n");
        return ;
    }
    else if(del_parent->left_child==NULL&&del_parent->right_child==NULL)//del_parent should be del
    {
        del=del_parent;
    }
    else if((del_parent->left_child)->key==k)//刪除的是parent的左節點
    {
        del=del_parent->left_child;

    }
    else if((del_parent->right_child)->key==k)//the parent's right_child is deleted element
    {
        del=del_parent->right_child;
    }

    //there is no leaf tree at deleted node
    if(del->left_child==NULL&&del->left_child==NULL)
    {
        if(del_parent->left_child==del)
        {
            del_parent->left_child=NULL;
        }
        else if(del_parent->right_child==del)
        {
            del_parent->right_child=NULL;
        }
        else//del_parent==del
        {
            del_parent=NULL;
        }
        free(del);
        return ;
    }

    //there is no left tree at deleted node
    if(del->left_child==NULL)
    {
        if(del_parent==del)//deleted element is root
        {
            del->key=(del->right_child)->key;//del's right child replace the root
            ptr_left=(del->right_child)->left_child;
            ptr_right=(del->right_child)->right_child;
            free(del->right_child);//deleted the former del's right child
            del->left_child=ptr_left;//link teh root to former (del's right child)'s child
            del->right_child=ptr_right;
            return ;
        }
        else if(del_parent->left_child==del)//deleted element is his'parent's left child
        {
            del_parent->left_child=del->right_child;
            free(del);
            return ;
        }
        else if(del_parent->right_child==del)//deleted element is his parent's right child
        {
            del_parent->left_child=del->left_child;
            free(del);
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
            del->left_child=ptr_left;//link teh root to former (del's left child)'s child
            del->right_child=ptr_right;
            return ;
        }
        else if(del_parent->left_child==del)//deleted element is his'parent's left child
        {
            del_parent->left_child=del->left_child;
            free(del);
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
        del=ptr_left;//ptr_left replace the del
        free(ptr_left);//deleted former left child's node
    }
}

tree_pointer del_search(tree_pointer node,int k)
{
    tree_pointer temp = node;
	if(!node)//tree is empty
	{
        printf("a\n");
		return NULL;
	}
	while(temp)//it is not in this tree(reach leaf)
	{
                printf("b\n");
		if(k==temp->key)//find it !
        {
            return node; //return the deleted element's parents or root node(first round)
        }
        node=temp;//so node can be temp's parent(after 1 round) , temp can use to test if it reach the leaf of the tree
        if(k>temp->key)// k is greater than this nood
		{        printf("c\n");

            temp=temp->right_child;//go to right
		}
		else
		{        printf("d\n");
			temp=temp->left_child;//go to left
		}
        //now temp is possible to be the leaf
	}
	return NULL;//not find
}
/*
void level_order(tree_pointer root)
{
	int front=0,rear=0;
	tree_pointer queue[MAX_TREE]={NULL};
	tree_pointer ptr;
	if(!(root))//tree is empty
	{
		printf("empty tree!\n");
		return;
	}
	else
	{
		if(rear==MAX_TREE-1)
		{
			printf("the tree's node is too many!\n");
			return;
		}
		queue[++(rear)]=root;
		if(front==rear)
		{
			printf("the queue is already empty! it can not be delete!\n");
			return;
		}
		queue[++(front)];
		while(rear!=front)
		{
			printf("%d",ptr->key);
			if(ptr->left_child)
			{
				if(rear==MAX_TREE-1)
				{
					printf("the tree's node is too many!\n");
					break;
				}
				queue[++(rear)]=ptr->left_child;
			}
			else
			{
				//tree_pointer temp=(tree_pointer) malloc(sizeof(tree_pointer));
				queue[++(rear)]=NULL;
			}
			if(ptr->right_child)
			{
				//level_order_add(queue,ptr->right_child,&rear);
				if(rear==MAX_TREE-1)
				{
					printf("the tree's node is too many!\n");
					break;
				}
				queue[++(rear)]=ptr->right_child;
			}
			//ptr=level_order_del(queue,&front,&rear);
			if(front==rear)
			{
				printf("the queue is already empty! it can not be delete!\n");
				break;
			}
				return queue[++(front)];
		}
	}
}
/*
void level_order_add(tree_pointer queue[],tree_pointer node,int *rear)
{
	if(*rear==MAX_TREE-1)
	{
		printf("the tree's node is too many!\n");
		return;
	}
	queue[++(*rear)]=node;
}
tree_pointer level_order_del(tree_pointer queue[],int *front,int *rear)
{
	if(*front==*rear)
	{
		printf("the queue is already empty! it can not be delete!\n");
		return;
	}
	return queue[++(*front)];
}*/
