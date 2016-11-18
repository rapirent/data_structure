/*****
title:fasttraspose
author:丁國騰
student ID:E94036209
description:fasttraspose one spare matrix
*****/ 
#include<stdlib.h>
#include<stdio.h>
#define  MAX_COL 100//最多有幾行
typedef struct
{
	int row;
	int col;
	int value;
}term;
term a[9],b[9];
void fastTranspose(term a[], term b[]);
int main(void) 
{
	a[0].row=6;
	a[0].col=6;
	a[0].value=8;
	a[1].row=0;
	a[1].col=0;
	a[1].value=15;
	a[2].row=0;
	a[2].col=3;
	a[2].value=22;
	a[3].row=0;
	a[3].col=5;
	a[3].value=-15;
	a[4].row=1;
	a[4].col=1;
	a[4].value=11;
	a[5].row=1;
	a[5].col=2;
	a[5].value=3;
	a[6].row=2;
	a[6].col=3;
	a[6].value=-6;
	a[7].row=4;
	a[7].col=0;
	a[7].value=91;
	a[8].row=5;
	a[8].col=2;
	a[8].value=28;
	int i;
	for(i=0;i<9;i++)
	{
		printf("a[%d].row=%d,a[%d].col=%d,a[%d].value=%d\n",i,a[i].row,i,a[i].col,i,a[i].value);
	}
	fastTranspose(a,b);
	printf("\n");
	for(i=0;i<9;i++)
	{
		printf("b[%d].row=%d,b[%d].col=%d,b[%d].value=%d\n",i,b[i].row,i,b[i].col,i,b[i].value);
	}
	system("pause");
	return 0;
}
void fastTranspose(term a[], term b[])
{
	int rowPos[MAX_COL];//只有一個陣列
	int i,j,temp,tempNext,numCols=a[0].col,numTerms=a[0].value;
	b[0].row=numCols;//存放a[0].col 
	b[0].col=a[0].row;//轉置
	b[0].value=numTerms;
	if(numTerms>0)//矩陣非零 
	{
		for(i=0;i<numCols;i++)//col最多只到numCol,又陣列從0開始 
		{
			rowPos[i]=0;//歸零
		}
		for(i=1;i<=numTerms;i++)//掃描所有元素,看這些元素各在哪一行! 
		{
			rowPos[(a[i].col)]++;//紀錄numCol個行中的每一行有幾個有值存在 
		}
		for(i=0;i<numCols;i++)
		{
			printf("rowPos[%d]=%d\n",i,rowPos[i]);
		}
		for(i=0;i<=numCols;i++)
		{
			if(i==0)
			{
				tempNext=rowPos[0];
				rowPos[0]=1;
			}
			else
			{
				temp=tempNext;
				tempNext=rowPos[i];
				rowPos[i]=rowPos[i-1]+temp;
			}
		}
		printf("numCols=%d\n",numCols);
		for(i=0;i<numCols;i++)
		{
			
			printf("rowPos[%d]=%d\n",i,rowPos[i]);
		}
		for(i=1;i<=numTerms;i++)
		{
			j=rowPos[a[i].col];
			b[j].row=a[i].col;
			b[j].col=a[i].row;
			b[j].value=a[i].value;
			rowPos[a[i].col]++; 
		}
	} 
	
} 
