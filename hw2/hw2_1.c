/*****
title:data structure hw2_1
author:丁國騰
student ID:E94036209
description:fasttraspose one spare matrix
*****/ 
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define  MAX_COL 100//最多有幾行
typedef struct
{
	int row;
	int col;
	int value;
}term;
void fastTranspose(term a[], term b[]);
int main(void) 
{
	char charRow,charCol;
	int row,col;
	printf("請依序輸入列數(row)和行數(col)(皆須大於零)\n");
	scanf("%d%d",&row,&col);
	if(row>0&&col>0)
	{
		printf("請依照行的順序依序填完每列中的元素\n");
		term a[(row*col)];
		term b[(row*col)];
		a[0].row=b[0].col=row;
		a[0].col=b[0].row=col;
		int countCol,input,countValue,countRow;
		for(countRow=0,countValue=1;countRow<row;countRow++)//共要輸入幾列 
		{
			for(countCol=0;countCol<col;countCol++)//共要輸入幾行數字 
			{
				scanf("%d",&input);
				if(input!=0)
				{
					a[countValue].value=input;
					a[countValue].row=countRow;
					a[countValue].col=countCol;
					countValue++;
				}
			}
		}
		a[0].value=b[0].value=countValue-1;
		int i;
		fastTranspose(a,b);
		for(countRow=0,countValue=1;countRow<col;countRow++)
		{
			if(b[countValue].row!=countRow)
			{
				printf(" 0 ");
			}
			for(countCol=0;countCol<row;countCol++)
			{
				if(b[countValue].col!=countCol)
				{
					printf(" 0 ");
				}
				else
				{
					printf(" %d ",b[countValue].value);
					countValue++;
				}
			
			}
			printf("\n");
		}
	}
	else
	{
		printf("請輸入正確的列或行數!\n");
	}
	system("pause");
	return 0;
}
void fastTranspose(term a[], term b[])
{
	int rowPos[a[0].value];//只有一個陣列
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
