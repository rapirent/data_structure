/*****
Title:data_structure_hw01
Author:¤B°êÄË
Student ID:E94036209
Description:use iterative and recursive way to compute a binomial coefficient. 
*****/ 
#include<stdio.h>
int iterahsuen(int n,int m)//°j°é 
{
	int k=n-m;
	int a=1,b=1,c=1;
	for(;n>0;n--)
	{
		a*=n;
	}
	for(;m>0;m--)
	{
		b*=m;
	}
	for(;k>0;k--)
	{
		c*=k;
	}
	return a/(b*c);
}
int recurhsuen(int n,int m)//»¼°j 
{
	if(n==m||m==1)
	{
		return n/m;
	}
	else
	{
		return recurhsuen(n-1,m)+recurhsuen(n-1,m-1);
	}
}
int main(void)
{
	int inputa,inputb;//C a¨úb
	while(scanf("%d%d",&inputa,&inputb)!=EOF&&(inputa>0&&inputb>0&&inputa>=inputb))
	{
		printf("%d(iterative function)\n",iterahsuen(inputa,inputb));
		printf("%d(recursive function)\n",recurhsuen(inputa,inputb)); 
	}
	return 0;
}
