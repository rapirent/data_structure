/*****
title:data structure hw3_1
author:�B����
student ID:E94036209
description:�p��e�m��ܪk 
*****/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct listnode
{
	char data;
	struct listnode *next;//���� 
	struct listnode *before;//���e 
};
typedef struct listnode node;
struct stacknode
{
	int data;
	struct stacknode *next;
};
typedef struct stacknode shuNode;
node* push(node* front,char in);
void deleteNode(node* front) ;
shuNode* shuPush(shuNode* front,int in);
int calculate(char in,int shu1,int shu2);
int pop(shuNode* front);
int main(void)
{
	char prefix[100];
	node* inputFront=NULL;//�e�� 
	node* input=NULL;
	node* inputRear=NULL;//���� 
	scanf("%s",prefix);
	int count=0;
	for(;count<strlen(prefix);count++)
	{
		if(prefix[count]!=' ')
		{
			inputFront=push(inputFront,prefix[count]);//push�F��i�h
		}
	}
	input=inputFront;
	while(input->next!=NULL)
	{
		input=input->next;
	}
	inputRear=input;//�x�s���� 
	shuNode* dueTop=NULL;//�˭Ӱ��|�a! 
	int shu,shu1,shu2;
	do
	{
		switch(inputRear->data)
		{
        	case '+': 
			case '-': 
			case '*': 
			case '/': 
			case '%':
				shu1=pop(dueTop);
				shu2=pop(dueTop);
            	shu=calculate(inputRear->data,shu1,shu2);
            	dueTop=shuPush(dueTop,shu);
            	break;
        	default://�B�⤸
        		sscanf((inputRear->data),"%d",&shu);
            	dueTop=shuPush(dueTop,shu);
		}
		inputRear=inputRear->before;
	}while(inputRear!=inputFront);//�S����!
	deleteNode(inputFront);
	printf("���G�O:%d\n",pop(dueTop));
}
/***�r����M��*****/
node* push(node* front,char in)//���|�W�h 
{ 
    node* input=(node*)malloc(sizeof(node));
	if(input=NULL)//�S�������O���� 
	{
		printf("error\n");
		exit(1);
	}
	input->data=in;
	if(front!=NULL)//���|�٦��F��!
	{
		front->before=input;
		input->next=front;
		input->before=NULL;
		front=input;
	}
	else//�ۤv�O�Ĥ@�� 
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
        printf("��C�w�šI\n"); 
    } 
    else
    {
		node* temp=front;
    	front = front->next; 
    	free(temp);
	}
} 
/***�r����M��*****/ 
/***�Ʀr��M��*****/ 
shuNode* shuPush(shuNode* front,int in)
{
	shuNode* input=(shuNode*)malloc(sizeof(shuNode));
	if(input==NULL)//�S�������O���� 
	{
		printf("error\n");
		exit(1);
	}
	input->data=in;
	if(front!=NULL)//���|�٦��F��!
	{
		input->next=front;
		front=input;
	}
	else//�ۤv�O�Ĥ@�� 
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
/***�Ʀr��M��*****/ 
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
