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
	//struct listnode *next;//���� 
	struct listnode *before;//���e 
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
	node* inputFront=NULL;//�e�� 
	node* input=NULL;
	node* inputRear=NULL;//���� 
	scanf("%s",prefix);
	int count=0;
				printf("a\n");
	for(;count<strlen(prefix);count++)
	{
						printf("b\n");

		if(prefix[count]!=' ')
		{
			inputFront=push(inputFront,prefix[count]);//push�F��i�h
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
	//inputRear=input;//�x�s���� 
	shuNode* dueTop=NULL;//�˭Ӱ��|�a!
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
        	default://�B�⤸
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
	}while(inputRear!=inputFront);//�S����!
	deleteNode(inputFront);
	printf("���G�O:%d\n",pop(dueTop));
}
/***�r����M��*****/
node* push(node* front,char in)//���|�W�h 
{ 
    node* input=(node*)malloc(sizeof(node));
	if(input==NULL)//�S�������O���� 
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
