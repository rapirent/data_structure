/*****
title:data structure hw3_1
author:丁國騰
student ID:E94036209
description:計算前置表示法 
*****/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct listnode
{
	char data;
	//struct listnode *next;//之後 
	struct listnode *before;//之前 
}node;
//typedef struct listnode node;
struct stacknode
{
	int data;
	struct stacknode *next;
}shuNode;
//typedef struct stacknode shuNode;
node* push(node* front,char in);
void deleteNode(node* front) ;
shuNode* shuPush(shuNode* front,int in);
int calculate(char in,int shu1,int shu2);
int pop(shuNode* front);
int main(void)
{
	char prefix[100];
	node* inputFront=NULL;//前端 
	node* input=NULL;
	node* inputRear=NULL;//尾巴 
	scanf("%s",prefix);
	int count=0;
				printf("a\n");
	for(;count<strlen(prefix);count++)
	{
						printf("b\n");

		if(prefix[count]!=' ')
		{
			inputFront=push(inputFront,prefix[count]);//push東西進去
		}
					printf("d\n");

	}
	inputRear=inputFront;
	while(inputRear->next!=NULL)
	{
					printf("c\n");
		printf("data=%c\n",inputRear->data);
		inputRear=inputRear->next;
	}
	//inputRear=input;//儲存尾端 
	shuNode* dueTop=NULL;//弄個堆疊吧!
	shuNode* countDue=NULL; 
	int shu,shu1,shu2;
	printf("data=%c\n",inputRear->data);
	do
	{
					printf("f\n");
		switch(inputRear->data)
		{
			printf("h\n");
        	case '+': 
			case '-': 
			case '*': 
			case '/': 
			case '%':
				shu1=pop(dueTop);
				shu2=pop(dueTop);
            	shu=calculate(inputRear->data,shu1,shu2);
            	dueTop=shuPush(dueTop,shu);
            				printf("h1\n");
            	break;
        	default://運算元
        		shu=inputRear->data-48;//sscanf(inputRear->data,"%d",&shu);
            	dueTop=shuPush(dueTop,shu);
            				printf("shu=%d\n",shu);

		}
		count=0;
		for(countDue=dueTop;countDue->next!=NULL;countDue=countDue->next)
		{
			printf("dueTop[%d]=%d",count,countDue->data);
			count++;
		}
		inputRear=inputRear->before;
	}while(inputRear!=inputFront);//沒走完!
	deleteNode(inputFront);
	printf("結果是:%d\n",pop(dueTop));
}
/***字元堆專區*****/
node* push(node* front,char in)//堆疊上去 
{ 
    node* input=(node*)malloc(sizeof(node));
	if(input==NULL)//沒有足夠記憶體 
	{
		printf("error\n");
		exit(1);
	}
	input->data=in;
	if(front!=NULL)//堆疊還有東西!
	{
		front->before=input;
		input->next=front;
		input->before=NULL;
		front=input;
	}
	else//自己是第一個 
	{
		input->next=NULL;
		input->before=NULL;
		front=input;
	}
	return front;
}
void deleteNode(node* front) 
{
    if(front->next == NULL) 
	{ 
        printf("佇列已空！\n"); 
    } 
    else
    {
		node* temp=front;
    	front = front->next; 
    	free(temp);
	}
} 
/***字元堆專區*****/ 
/***數字堆專區*****/ 
shuNode* shuPush(shuNode* front,int in)
{
	shuNode* input=(shuNode*)malloc(sizeof(shuNode));
	if(input==NULL)//沒有足夠記憶體 
	{
		printf("error\n");
		exit(1);
	}
	input->data=in;
	if(front!=NULL)//堆疊還有東西!
	{
		input->next=front;
		front=input;
	}
	else//自己是第一個 
	{
		input->next=NULL;
		front=input;
	}
	return front;
}
int pop(shuNode* front)
{
	if(front!=NULL)
	{
		int temp=front->data;
		free(front);
		return temp;
	}
}
/***數字堆專區*****/ 
int calculate(char in,int shu1,int shu2)
{
	switch(in)
	{
		case '+':
			return (shu1+shu2);
		case '-':
			return (shu1-shu2);
		case '*':
			return (shu1*shu2);
		case '/':
			return (shu1*shu2);
		case '%':
			return (shu1%shu2);
	}
}
