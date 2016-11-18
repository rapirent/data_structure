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
	printf("!!\n");
	tree_pointer ptr=NULL,temp=NULL;
	temp=insert_search(*node,k);//now temp is the final node of the tree
	if(temp||(!(*node)))//if temp==0&&(*node)!=0, so there is already an element in tree
	{
		printf("0\n");
		ptr = (tree_pointer)malloc(sizeof(struct tree)); // allocate the space to ptr
		ptr->key=k;//ptr restore the key
		ptr->left_child=NULL;
		ptr->right_child=NULL;
		if(*node)//if tree is not empty
		{
            printf("9\n");
			if(k>temp->key)
			{
				temp->right_child=ptr;//greater than key, so insert at his right
				printf("1\n");
			}
            else if(k==temp->key)
            {
                printf("喵的\n");
            }
			else
			{
				temp->left_child = ptr;
				printf("2\n");
			}
		}
		else//insert in an empty tree
		{
			*node=ptr;
			printf("3\n");
		}
	}
    if(temp==NULL)printf("=\n");
    if(*node)printf("^\n");//*node==1
    printf("temp=%p\n",temp);
    printf("*node=%p\n",*node);
}

tree_pointer insert_search(tree_pointer node,int k)//find the final node
{
    tree_pointer temp = node;
	if(!node)//this tree is empty
	{printf("?\n");
		return NULL;//it can be added
	}
	while(temp)
	{
        node=temp;
		printf("X\n");
		if(k==node->key)//find it !
		{printf("Y\n");
			return NULL;//it can't be added!
		}
		else if(k>(node->key))//greater than key , go to right
		{printf("Y1\n");
			temp=node->right_child;
		}
		else//go to left
		{printf("Y2\n");
			temp=node->left_child;
		}
	}
	printf("Z\n");
	printf("%p",node);
	return node;
}

void delTree(tree_pointer *root,int key)
{
	tree_pointer ptr_right=NULL,ptr_left=NULL,temp=NULL;
	temp=del_search(*root,key);
	if(temp)//if temp==NULL, the tree can't be deleted
	{//now temp is the key's place
		ptr_right = temp->right_child;
		ptr_left = temp->left_child;
		while(!(ptr_left->right_child))//when it reach temp's right tree's end
		{
			ptr_left=ptr_left->right_child;
		}//now, ptr is the greater node in key's left child tree!
		ptr_left->right_child=ptr_right;
		free(temp);//delete temp
	}
}

tree_pointer del_search(tree_pointer node,int k)
{
	if(!node)//tree is empty
	{
		return NULL;
	}
	while(node->key!=k&&node!=NULL)//find it or it is not in this tree
	{
		if(k>node->key)// k is greater than this nood
		{
			node=node->left_child;//go to left
		}
		else
		{
			node=node->right_child;//go to right
		}
	}
	return node;//NULL or really element's place
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
