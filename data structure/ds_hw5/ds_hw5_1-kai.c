#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX_TREE 1000

struct tree{
	int key;//key
	int flag;//level num
	struct tree *right_child;
	struct tree *left_child;
};
typedef struct tree* tree_pointer;

int union_tree[MAX_TREE]={0};
/**********************************************************/
void insert(tree_pointer *node,int k);
tree_pointer insert_search(tree_pointer node,int k);
/**********************************************************/
void delTree(tree_pointer *root,int key);
tree_pointer del_search(tree_pointer nood,int k,tree_pointer*);
/**********************************************************/
void level_order(tree_pointer *);
int level_order_search(tree_pointer node);

int main(void){
	char input[10000]={'\0'};
 	char *temp;
	tree_pointer root=NULL;
    int first_blank=1;
    int now_shu_degree=0;
    int input_shu;
    printf("請輸入節點內容(大於等於零)來製造二元搜尋樹(右子節點較大,左子節點較小)(以空白或換行鍵隔開):\n");
    printf("(輸入E來顯示當前二元搜尋樹的內容,輸入D來刪除二元搜尋樹節點)\n");
    while(scanf("%s",input)!=EOF)
    {
        temp=strtok(input," ");
        if(input[0]=='E')
        {
            //level_order(root);
            printf("當前二元搜尋樹的內容為(為了完整呈現,顯示直到元素存在的那階為止,若有空節點則以X呈現):\n");
            level_order(&root);
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
            //printf("shu=%d\n",input_shu);
            while((temp = strtok(NULL," ")))
            {
                input_shu=atoi(temp);
                insert(&root,input_shu);
                //printf("shu=%d\n",input_shu);
            }
            //insert
        }

    }
    printf("請輸入節點內容(大於等於零)來刪除節點(以空白或換行鍵隔開)\n");
    while(scanf("%s",input)!=EOF)
    {
        //printf("a\n");
        temp=strtok(input," ");
        if(input[0]=='E')
        {
            printf("當前二元搜尋樹的內容為(為了完整呈現,顯示直到元素存在的那階為止,若有空節點則以X呈現):\n");
            level_order(&root);
            return 0;
        }
        else
        {
            input_shu=atoi(temp);
            //printf("shu=%d\n",input_shu);
            delTree(&root,input_shu);
            while((temp = strtok(NULL," ")))
            {
                input_shu=atoi(temp);
                delTree(&root,input_shu);
                //printf("shu=%d\n",input_shu);
            }
        }
    }
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
                //printf("TEST\n");
			}
		}
		else//insert in an empty tree
		{
			*node=ptr;
		}
	}
    else
    {
        printf("the node can not be added!\n");
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
	del_parent=del_search(*root,k,&del);//find the deleted element's parent , if element is root, then temp_parent==temp
    if(del_parent==NULL)
    {
        printf("the tree can not be deleted!\n");
        return ;
    }
    //delete the leaf node
    if(del->right_child==NULL&&del->left_child==NULL)
    {
        //printf("^^^^\n");
        if(del_parent->left_child==del)
        {
                    //printf("----\n");
            del_parent->left_child=NULL;
            free(del);
        }
        else if(del_parent->right_child==del)
        {//printf("---\n");
            del_parent->right_child=NULL;
            free(del);
        }
        else//del is root node
        {//printf("--\n");
            del_parent=NULL;
            free(del);
        }
        return ;
    }

    //there is no left tree at deleted node
    if(del->left_child==NULL)
    {
        //printf("^^^\n");
        if(del_parent==del)//deleted element is root
        {
            del->key=(del->right_child)->key;//del's right child replace the root
            ptr_left=(del->right_child)->left_child;
            ptr_right=(del->right_child)->right_child;
            free(del->right_child);//deleted the former del's right child
            del->right_child=NULL;
            del->left_child=ptr_left;//link teh root to former (del's right child)'s child
            del->right_child=ptr_right;
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
            del=NULL;
            return ;
        }
        else
        {
            printf("ERORR\n");
        }
    }
    //no right tree at deleted node
    if(del->right_child==NULL)
    {
        //printf("^^\n");
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
            del_parent->right_child=del->left_child;
            free(del);
            del=NULL;
            return ;
        }
        else
        {
            printf("ERORR\n");
        }
    }
    //deleted node has two child
    if(del->right_child!=NULL&&del->left_child!=NULL)
    {
        //printf("^\n");
        ptr_left=del->left_child;
        ptr_right=del->right_child;
        ///left child only 1
        if(ptr_left->right_child==NULL)
        {
            del->key=ptr_left->key;
            del->left_child=ptr_left->left_child;
            free(ptr_left);
            ptr_left=NULL;
            return ;
        }
        ///left child has right child
        while((ptr_left->right_child)!=NULL)
        {
            ptr_left=ptr_left->right_child;
        }//now the ptr_left is best num among del's left tree
        if(ptr_left->left_child!=NULL)//rightest child in del's left tree has left child
        {
            del->key=ptr_left->key;//rightest child in del's left tree replace del
            ptr_left->key=(ptr_left->left_child)->key;//rightest child in del's left tree's left child replace his parent
            free(ptr_left->left_child);
            ptr_left->left_child=NULL;
            return ;
        }
        else//rightest child in del's left tree has no left child
        {
            del->key=ptr_left->key;//rightest child in del's left tree replace del
            free(ptr_left);
            ptr_left=NULL;
            return ;
        }
    }
}
tree_pointer del_search(tree_pointer node,int k, tree_pointer *del)
{
    tree_pointer after = node;
	if(!node)//tree is empty
	{
        //printf("A1\n");
		return NULL;
	}
	while(after)//it is not in this tree(reach leaf)
	{
                //printf("A2\n");
		if(k==after->key)//find it !
        {
                    //printf("A3\n");
            *del=after;
            return node; //return the deleted element's parents or root node(first round)
        }
        node=after;//so node can be temp's parent(after 1 round) , temp can use to test if it reach the leaf of the tree
        if(k>node->key)// k is greater than this nood
		{
        //printf("A4\n");
            after=after->right_child;//go to right
		}
		else
		{
                    //printf("A5\n");
			after=after->left_child;//go to left
		}
        //now temp is possible to be the leaf
	}
	return NULL;//not find
}
void level_order(tree_pointer *root)
{
    tree_pointer traversal_queue[MAX_TREE]={NULL};
    tree_pointer ptr=NULL;
    int front,rear;
    front=rear=-1;
    int degree=level_order_search(*root);//get the rightest node in tree(largest degree)
    int count_for_degree,temp_2=1;
    for(count_for_degree=1;count_for_degree<=degree;count_for_degree++)
    {
        temp_2*=2;
    }
    int count_for_trave=temp_2-1;
    //printf("count_for_trave=%d\n",count_for_trave);
    //printf("degree=%d\n",degree);
    if(!(*root))
    {
        //printf("the tree is empty!\n");
        return ;
    }
    //////add root
    if(rear==MAX_TREE-1)
    {
        printf("the queue is full!\n");
    }
    else
    {
        traversal_queue[++rear]=*root;
    }
    while(rear+1<count_for_trave)
    {
        if(front==rear)
        {
            printf("the queue is empty!\n");
            break;
        }
        else
        {
            ptr=traversal_queue[++front];
        }
        //if(rear+1<count_for_trave)
        //{
            if(ptr->key==-1)
            {
                printf(",X");
            }
            else
            {

                if(ptr==*root)
                {
                    printf("%d",ptr->key);
                }
                else
                {
                    printf(",%d",ptr->key);
                }
            }
            if(rear==MAX_TREE-1)
            {
                printf("the queue is full!\n");
                break;
            }
            else
            {
                if(ptr->left_child==NULL)
                {
                        traversal_queue[++rear]=(tree_pointer)malloc(sizeof(struct tree));
                        traversal_queue[rear]->key=-1;
                        traversal_queue[rear]->right_child=traversal_queue[rear]->left_child=NULL;
                }
                else
                {
                    traversal_queue[++rear]=ptr->left_child;
                }
            }
            if(rear==MAX_TREE-1)
            {
                printf("the queue is full!\n");
                break;
            }
            else
            {
                if(ptr->right_child==NULL)
                {
                        traversal_queue[++rear]=(tree_pointer)malloc(sizeof(struct tree));
                        traversal_queue[rear]->key=-1;
                        traversal_queue[rear]->right_child=traversal_queue[rear]->left_child=NULL;
                }
                else
                {
                    traversal_queue[++rear]=ptr->right_child;
                }
            }

        //}
        //else break;
    }
    while(rear!=front)
    {
        ptr=traversal_queue[++front];
        if(ptr->key==-1)
        {
                printf(",X");
        }
        else
        {
            if(ptr==*root)
            {
                    printf("%d",ptr->key);
            }
            else printf(",%d",ptr->key);
        }
    }
}

int level_order_search(tree_pointer node)
{
    if(node->right_child==NULL&&node->left_child==NULL)
    {
        return 1;
    }
    int l,r;
    if(node->left_child!=NULL)l=level_order_search(node->left_child);
    if(node->right_child!=NULL)r=level_order_search(node->right_child);
    if(l>r)
    {
        return l+1;
    }
    else
    {
        return r+1;
    }
}