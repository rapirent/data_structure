#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACK_MAX 80
char input[STACK_MAX]={'\0'};
int stack[STACK_MAX];
int eval(int eval_shu1,int eval_shu2,char oper)//��J��ӼƩM�@�ӹB��l
{
	switch(oper)
	{
		case '+':
			return eval_shu1+eval_shu2;
		case '-':
			return eval_shu1-eval_shu2;
		case '*':
			return eval_shu1*eval_shu2;
		case '/':
			return eval_shu1/eval_shu2;
		case '%': 
			return eval_shu1%eval_shu2;
	}
} 
int main(void)
{
	int count=0;
	for(;count<STACK_MAX;count++)
	{
		stack[count]=-1;//��l�� 
	}
	gets(input);
	int len=strlen(input);
	count=len-1;
	int shu;
	int eval_shu1,eval_shu2;
	int count2=0;
	for(;count>=0;count--)
	{
		switch(input[count])
		{
			case ' ':
			case '\0':
				break;
			case '+': //�B��l 
         	case '-': 
         	case '*':
         	case '/':
         	case '%': 
			 	count2--;//pop!!!
         		eval_shu1=stack[count2];
         		count2--;	
         		eval_shu2=stack[count2];
         		shu=eval(eval_shu1,eval_shu2,input[count]);
         		stack[count2]=shu;
         		count2++;
				break;
			default://�B�⤸ 
				shu=input[count]-'0';
				stack[count2]=shu;
				count2++;//push
				break;
		} 
	}
	printf("\n%d",stack[0]);
	return 0;
}

