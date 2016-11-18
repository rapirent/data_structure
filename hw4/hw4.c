#include<stdlib.h>
#include<stdio.h>
#define max_size 100

struct node//link list的node 
{
	int row;
	int col;
	int value;
	struct node* next;
};
typedef struct node* node_pointer;//link list的node point define 
void print(node_pointer c,int a_row,int b_col);
void read_matrix(node_pointer *first,int row,int col);
node_pointer mult(node_pointer a,node_pointer b);
int main(void)
{
	int count_col,count_row,num_col_a,num_row_a,num_col_b,num_row_b;
	node_pointer a=NULL,b=NULL;
	printf("請依序輸入陣列的行數和列數\n");
	scanf("%d %d",&num_row_a,&num_col_a);
	if(num_col_a<=0||num_row_a<=0)
	{
		printf("請輸入正確的行列數!\n"); 
		return 0;
	}	
	else
	{
		read_matrix(&a,num_row_a,num_col_a);
	}
	node_pointer temp=a;
	printf("請依序輸入第二個陣列的行數和列數\n");
	scanf("%d %d",&num_row_b,&num_col_b);
	if(num_col_b<=0||num_row_b<=0)
	{
		printf("請輸入正確的行列數!\n");
		return 0;
	}
	else
	{
		read_matrix(&b,num_row_b,num_col_b);
	}
	node_pointer c;
	c=mult(a,b);
	print(c,num_row_a,num_col_b);

	return 0;
}
void read_matrix(node_pointer *first,int num_row,int num_col)
{
	int value,count_row,count_col;
	node_pointer temp=NULL,rear=NULL;
	for(count_row=0;count_row<num_row;count_row++)
	{
		for(count_col=0;count_col<num_col;count_col++)
		{
			scanf("%d",&value);
			if(value!=0)
			{
				temp=(node_pointer)malloc(sizeof(struct node));
				if(*first==NULL)//第一個節點
				{
					*first=temp;
					rear=temp;
					temp->next=NULL;
				}
				else
				{
					rear->next=temp;
					rear=temp;
					temp->next=NULL;
				}
				temp->row=count_row;
				temp->col=count_col;
				temp->value=value;
			}
		}
	}
}

node_pointer mult(node_pointer a,node_pointer b)
{
	node_pointer c,tempb,rear,temp;  
	rear=NULL;
	for(tempb=b;a!=NULL;a=a->next)
	{
		for(;tempb;tempb=tempb->next)
		{
			if((a->col)==(tempb->row))
			{
				temp=(node_pointer)malloc(sizeof(struct node));	
				temp->row=a->row;     
				temp->col=tempb->col;     
				temp->value=(a->value)*(tempb->value);
				if(rear!=NULL)
				{
					rear->next=temp;
					rear=temp;
					temp->next=NULL;
				}
				else
				{
					c=temp;
					rear=temp;
				}
			}
		}  
		tempb=b;
	}
    return c;
}
void print(node_pointer c,int num_row,int num_col)//輸出 
{       
	int print[num_row][num_col],i,j;     //取第一次輸入的row,第二次的col
	for(i=0;i<num_row;i++)
	{
		for(j=0;j<num_col;j++)
		{
			print[i][j]=0;//初始化 
		}
	}
	for(;c;c=c->next)
	{
		print[c->row][c->col]+=c->value;
	}
	for(i=0;i<num_row;i++)
	{
		for(j=0;j<num_col;j++)
		{
			printf(" %d ",print[i][j]);
		}
		printf("\n");
	}
}
