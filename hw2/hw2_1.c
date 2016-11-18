/*****
title:data structure hw2_1
author:�B����
student ID:E94036209
description:fasttraspose one spare matrix
*****/ 
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define  MAX_COL 100//�̦h���X��
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
	printf("�Ш̧ǿ�J�C��(row)�M���(col)(�Ҷ��j��s)\n");
	scanf("%d%d",&row,&col);
	if(row>0&&col>0)
	{
		printf("�Ш̷Ӧ檺���Ķ̌Ƕ񧹨C�C��������\n");
		term a[(row*col)];
		term b[(row*col)];
		a[0].row=b[0].col=row;
		a[0].col=b[0].row=col;
		int countCol,input,countValue,countRow;
		for(countRow=0,countValue=1;countRow<row;countRow++)//�@�n��J�X�C 
		{
			for(countCol=0;countCol<col;countCol++)//�@�n��J�X��Ʀr 
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
		printf("�п�J���T���C�Φ��!\n");
	}
	system("pause");
	return 0;
}
void fastTranspose(term a[], term b[])
{
	int rowPos[a[0].value];//�u���@�Ӱ}�C
	int i,j,temp,tempNext,numCols=a[0].col,numTerms=a[0].value;
	b[0].row=numCols;//�s��a[0].col 
	b[0].col=a[0].row;//��m
	b[0].value=numTerms;
	if(numTerms>0)//�x�}�D�s 
	{
		for(i=0;i<numCols;i++)//col�̦h�u��numCol,�S�}�C�q0�}�l 
		{
			rowPos[i]=0;//�k�s
		}
		for(i=1;i<=numTerms;i++)//���y�Ҧ�����,�ݳo�Ǥ����U�b���@��! 
		{
			rowPos[(a[i].col)]++;//����numCol�Ӧ椤���C�@�榳�X�Ӧ��Ȧs�b 
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
