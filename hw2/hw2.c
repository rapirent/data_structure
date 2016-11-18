/*****
title:data structure assignment2_homework2
author:丁國騰
student ID:E94036209
description:to solve knight's tour problem
*****/
#include<stdio.h>
#include<stdlib.h>
int board[8][8];
int ifExit (int i,int j);//檢查是否在範圍內 
int main(void)
{
	int ktmove1[8]={-2,-1,1,2,2,1,-1,-2};
	int ktmove2[8]={1,2,2,1,-1,-2,-2,-1};
	int i,j,m,k,l,npos,min,temp;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			board[i][j]=0;
		}
	}	
	int nexti[8],nextj[8],exits[8];
	printf("請輸入規定範圍(0~7)內的位置(x,y)\n");
	scanf("%d%d",&i,&j);
	if(ifExit(i,j)) 
	{
		board[i][j]=0;//初始囉 
		
		for(m=1;m<=64;m++)
		{
			for(k=0;k<8;k++)//每次都要初始化 
			{
				nexti[k]=nextj[k]=exits[k]=0;
			}
			//printf("-----------\nm=%d\n",m);
			npos=0;//用來記錄此點可以走幾個方向 
			min=0;//得到每次步數最小的l 
			l=0;//l分別記錄每個可以走的方向位置 
			for(k=0;k<8;k++)//k用來計算八次(巡邏八個方向)
			{
				if(ifExit(i+ktmove1[k],j+ktmove2[k]))//沒有被巡邏過
				{
						nexti[l]=i+ktmove1[k];
						nextj[l]=j+ktmove2[k]; 
						npos++;
						//printf("nexti[%d]=%d\nnextj[%d]=%d\n",l,nexti[l],l,nextj[l]);
						l++;
				}
			}
			//printf("npose:%d\n",npos);
			if(npos==0)
			{
				printf("巡邏失敗\n");
				break;	
			}
			else if(npos==1)//只有一個方向可以走,他被存在nexti[0],nextj[0]
			{
				min=0;
			}
			else
			{
				temp=8;//temp設最大,這樣一比就可以取得最小 
				min=0;
				for(l=0;l<npos;l++)//開始檢查上個迴圈得到可以走的方向們 
				{
					for(k=0;k<8;k++)
					{
						if(ifExit(nexti[l]+ktmove1[k],nextj[l]+ktmove2[k]))
						{
							exits[l]++;
						}
					}
					//printf("exits[%d]=%d\n",l,exits[l]);
					if(temp>exits[l])//讀取目前的exits,判斷是否比前面找到最小的還小,而找出最小的,照課本指示的規則,如果一樣小則拿第一個 
					{
						temp=exits[l];
						min=l;
					}
				}
				//printf("min=%d\n",min);
			}
			if(board[nexti[min]][nextj[min]]==0)//保險一下 
			{
				i=nexti[min];
				j=nextj[min];
				board[i][j]=m;
			} 
		}
		m--;
		if(m==64)
		{
			printf("巡邏完成\n"); 
		}
		printf("\n");
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				printf("%2d ",board[i][j]);
			}
			printf("\n");
		}
		printf("總共走了%d步\n",m);
	}
	else
	{
		printf("請輸入規定範圍內的位置!\n");
	}
	system("pause");
}

int ifExit(int i,int j)
{
	if((i>=0&&i<=7)&&(j>=0&&j<=7)&&(board[i][j]==0))
	{
		return 1;//對 
	}
	return 0;//錯誤
}
