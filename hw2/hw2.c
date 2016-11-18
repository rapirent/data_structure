/*****
title:data structure assignment2_homework2
author:�B����
student ID:E94036209
description:to solve knight's tour problem
*****/
#include<stdio.h>
#include<stdlib.h>
int board[8][8];
int ifExit (int i,int j);//�ˬd�O�_�b�d�� 
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
	printf("�п�J�W�w�d��(0~7)������m(x,y)\n");
	scanf("%d%d",&i,&j);
	if(ifExit(i,j)) 
	{
		board[i][j]=0;//��l�o 
		
		for(m=1;m<=64;m++)
		{
			for(k=0;k<8;k++)//�C�����n��l�� 
			{
				nexti[k]=nextj[k]=exits[k]=0;
			}
			//printf("-----------\nm=%d\n",m);
			npos=0;//�ΨӰO�����I�i�H���X�Ӥ�V 
			min=0;//�o��C���B�Ƴ̤p��l 
			l=0;//l���O�O���C�ӥi�H������V��m 
			for(k=0;k<8;k++)//k�Ψӭp��K��(���ޤK�Ӥ�V)
			{
				if(ifExit(i+ktmove1[k],j+ktmove2[k]))//�S���Q���޹L
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
				printf("���ޥ���\n");
				break;	
			}
			else if(npos==1)//�u���@�Ӥ�V�i�H��,�L�Q�s�bnexti[0],nextj[0]
			{
				min=0;
			}
			else
			{
				temp=8;//temp�]�̤j,�o�ˤ@��N�i�H���o�̤p 
				min=0;
				for(l=0;l<npos;l++)//�}�l�ˬd�W�Ӱj��o��i�H������V�� 
				{
					for(k=0;k<8;k++)
					{
						if(ifExit(nexti[l]+ktmove1[k],nextj[l]+ktmove2[k]))
						{
							exits[l]++;
						}
					}
					//printf("exits[%d]=%d\n",l,exits[l]);
					if(temp>exits[l])//Ū���ثe��exits,�P�_�O�_��e�����̤p���٤p,�ӧ�X�̤p��,�ӽҥ����ܪ��W�h,�p�G�@�ˤp�h���Ĥ@�� 
					{
						temp=exits[l];
						min=l;
					}
				}
				//printf("min=%d\n",min);
			}
			if(board[nexti[min]][nextj[min]]==0)//�O�I�@�U 
			{
				i=nexti[min];
				j=nextj[min];
				board[i][j]=m;
			} 
		}
		m--;
		if(m==64)
		{
			printf("���ާ���\n"); 
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
		printf("�`�@���F%d�B\n",m);
	}
	else
	{
		printf("�п�J�W�w�d�򤺪���m!\n");
	}
	system("pause");
}

int ifExit(int i,int j)
{
	if((i>=0&&i<=7)&&(j>=0&&j<=7)&&(board[i][j]==0))
	{
		return 1;//�� 
	}
	return 0;//���~
}
