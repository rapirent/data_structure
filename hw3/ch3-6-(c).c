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
		printf("�{�b�O%c\n",infix[count]); 
		switch(infix[count])
		{
			case ' ':
			case '\0':
				break;
			case ')'://�����s�J
				stack_top++;//stack�����ݥ[�@,�p�G�O�Ĥ@�ӫh��0 
				stack[stack_top]=infix[count];//�s�J)
				break;
			case '('://pop����) 
				while(stack[stack_top]!=')')//���O)�e=�~��pop
				{
					prefix_current++;
					//printf("stack�Y=%c\n",stack[stack_top]);
					prefix[prefix_current]=stack[stack_top];//pop�X��
					stack[stack_top]='\0';
					stack_top--;
				}
				if(stack[stack_top]==')')//�O�I
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
				while(priority(infix[count])<priority(stack[stack_top])&&stack[stack_top]!='\0')//stack�̳��ݭY�O��{�bŪ�쪺�B��l�j�hpop�X�� ex stack:*/ infix:- => prefix:*/
				{ 
					prefix_current++;
					//printf("stack=%c\n",stack[stack_top]);
					prefix[prefix_current]=stack[stack_top];//pop�X��
					stack[stack_top]='\0';
					stack_top--;
				}
				stack_top++;
				stack[stack_top]=infix[count];//push�i�h 
				break;
			default://�B�⤸ ex a b
				prefix_current++;
				prefix[prefix_current]=infix[count];
				break;
		}
	}
	while(stack_top!=-1)//stack���٦��F��
	{
		printf("stack_top=%d\n",stack_top); 
		printf("stack[top]=%c\n",stack[stack_top]);
		printf("prefix_current=%d\n",prefix_current);
		prefix_current++;
		prefix[prefix_current]=stack[stack_top];
		stack[stack_top]='\0';
		stack_top--;
	}
	while(prefix_current!=-1)//�ϦV�L�Xprefix! 
	{
		printf("%c",prefix[prefix_current]);
		prefix_current--;
	}
	printf("\n");
	return 0;
}
