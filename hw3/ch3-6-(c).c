#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACK_MAX 80
char infix[STACK_MAX]={'\0'};
char prefix[STACK_MAX]={'\0'};
char stack[STACK_MAX]={'\0'};
int priority(char oper)
{
	switch(oper)
	{
		case'+':return 12;         
		case'-':return 12;
		case'*':return 15;
		case'/':return 15;
		case'!':return 15;
		case'~':return 15;
		case'%':return 15;
		case'<':return 10;
		case'>':return 10;
		case'|':return 5;
		case'&':return 8;
		default:return 10;
	} 
}
int main(void)
{
	gets(infix);
	int len;
	len=strlen(infix)-1;
	int count,stack_top,prefix_current;
	stack_top=-1;
	prefix_current=-1;
	for(count=len;count>=0;count--)
	{
		printf("現在是%c\n",infix[count]); 
		switch(infix[count])
		{
			case ' ':
			case '\0':
				break;
			case ')'://直接存入
				stack_top++;//stack之頂端加一,如果是第一個則為0 
				stack[stack_top]=infix[count];//存入)
				break;
			case '('://pop直到) 
				while(stack[stack_top]!=')')//不是)前=繼續pop
				{
					prefix_current++;
					//printf("stack頭=%c\n",stack[stack_top]);
					prefix[prefix_current]=stack[stack_top];//pop出來
					stack[stack_top]='\0';
					stack_top--;
				}
				if(stack[stack_top]==')')//保險
				{
					stack[stack_top]='\0';
					stack_top--;
				}
				break;
			case'+':       
			case'-':
			case'*':
			case'/':
			case'!':
			case'~':
			case'%':
			case'<':
			case'>':
			case'|':    
			case'&':
				while(priority(infix[count])<priority(stack[stack_top])&&stack[stack_top]!='\0')//stack最頂端若是比現在讀到的運算子大則pop出來 ex stack:*/ infix:- => prefix:*/
				{ 
					prefix_current++;
					//printf("stack=%c\n",stack[stack_top]);
					prefix[prefix_current]=stack[stack_top];//pop出來
					stack[stack_top]='\0';
					stack_top--;
				}
				stack_top++;
				stack[stack_top]=infix[count];//push進去 
				break;
			default://運算元 ex a b
				prefix_current++;
				prefix[prefix_current]=infix[count];
				break;
		}
	}
	while(stack_top!=-1)//stack中還有東西
	{
		printf("stack_top=%d\n",stack_top); 
		printf("stack[top]=%c\n",stack[stack_top]);
		printf("prefix_current=%d\n",prefix_current);
		prefix_current++;
		prefix[prefix_current]=stack[stack_top];
		stack[stack_top]='\0';
		stack_top--;
	}
	while(prefix_current!=-1)//反向印出prefix! 
	{
		printf("%c",prefix[prefix_current]);
		prefix_current--;
	}
	printf("\n");
	return 0;
}
