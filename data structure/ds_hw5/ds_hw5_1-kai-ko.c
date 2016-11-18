#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX_TREE 1000

int shu[MAX_TREE];

void insert(int key);
void del(int key);
int find(int key);
void clear(void);
int tail(void);

int main(void)
{
	char input[10000]={'\0'};
 	char *temp;
    int input_shu;
    int final_element;
    int trave;
    printf("請輸入節點內容(大於等於零)來製造二元搜尋樹(右子節點較大,左子節點較小)(以空白或換行鍵隔開):\n");
    printf("(輸入E來顯示當前二元搜尋樹的內容,輸入D來刪除二元搜尋樹節點)\n");
    clear();
    while(fgets(input,MAX_TREE,stdin)!=NULL)
    {
        temp=strtok(input," ");
        if(input[0]=='E')
        {
            //level_order(root);
            printf("當前二元搜尋樹的內容為:\n");
            final_element=tail();
            for(trave=1;trave<=final_element;trave++)
            {
                if(shu[trave]!=-1)
                {
                    printf("%d",shu[trave]);
                }
                else
                {
                    printf("X");
                }
                if(trave+1<=final_element)
                {
                    printf(",");
                }
            }
            return 0;
        }
        else if(input[0]=='D')
        {
            //delete
            break;
        }
        else
        {
            input_shu=atoi(temp);
            insert(input_shu);
            printf("shu=%d\n",input_shu);
            while((temp = strtok(NULL," ")))
            {
                input_shu=atoi(temp);
                insert(input_shu);
                printf("shu=%d\n",input_shu);
            }
            //insert
        }

    }
    printf("請輸入節點內容(大於等於零)來刪除節點(以空白或換行鍵隔開)\n");
    while(fgets(input,MAX_TREE,stdin)!=NULL)
    {
        printf("a\n");
        temp=strtok(input," ");
        if(input[0]=='E')
        {
            printf("當前二元搜尋樹的內容為:\n");
            final_element=tail();
            for(trave=1;trave<=final_element;trave++)
            {
                if(shu[trave]!=-1)
                {
                    printf("%d",shu[trave]);
                }
                else
                {
                    printf("X");
                }
                if(trave+1<=final_element)
                {
                    printf(",");
                }
            }
            return 0;
        }
        else
        {
            input_shu=atoi(temp);
            printf("shu=%d\n",input_shu);
            del(input_shu);
            while((temp = strtok(NULL," ")))
            {
                input_shu=atoi(temp);
                del(input_shu);
                printf("shu=%d\n",input_shu);
            }
        }
    }
	return 0;
}

void clear(void)
{
    int count;
    for(count=0;count<MAX_TREE;count++)
    {
        shu[count]=-1;
    }
}

void insert(int key)
{
    int temp_index=1;//root!
    if(shu[1]==-1)//root has no element!
    {
        shu[1]=key;
        return ;
    }
    while(shu[temp_index]!=-1)
    {
        if(key==shu[temp_index])
        {
            printf("重複元素,無法建立樹!\n");
            exit(1);
        }
        else if(key>shu[temp_index])//key greater than temp , move left
        {
            temp_index=2*temp_index+1;
        }
        else if(key<shu[temp_index])//move right
        {
            temp_index=2*temp_index;
        }
    }
    shu[temp_index]=key;
}
void del(int key)
{
    int delete_index=find(key);
    int temp_index,temp;
    if((shu[2*delete_index+1]==-1)&&(shu[2*delete_index]==-1))//leaf node, directly delete
    {
        shu[delete_index]=-1;
        return ;
    }
    else if((shu[2*delete_index]==-1)&&(shu[2*delete_index+1]!=-1))//no left child,find min right child
    {
        temp_index=2*delete_index+1;
        while(shu[2*temp_index]!=-1)//看他的左子樹
        {
            temp_index=2*temp_index;
        }
        //現在shu[temp_index]為右子樹中最小的了
        temp=shu[temp_index];
        del(temp);
        shu[delete_index]=temp;
    }
    else if(shu[2*delete_index]!=-1)//has left child, find max left child
    {
        temp_index=2*delete_index;
        while(shu[2*temp_index+1]!=-1)//看他的右子樹
        {
            temp_index=2*temp_index+1;
        }
        //現在shu[temp_index]為左子樹中最大的了
        temp=shu[temp_index];
        del(temp);
        shu[delete_index]=temp;
    }
}
int find(int key)
{
    int find_index=1;
    if(shu[1]==-1)
    {
        printf("無此樹!無法尋找和刪除\n");
        exit(1);
    }
    while(key!=shu[find_index])
    {
        if(key>shu[find_index])
        {
            find_index=2*find_index+1;
        }
        else//key < shu[find_index]
        {
            find_index=2*find_index;
        }
        if(find_index>=MAX_TREE)
        {
            printf("請增加原始陣列最大長度!\n");
            exit(1);
        }
    }
    return find_index;
}

int tail(void)
{
    int anti_count;
    for(anti_count=MAX_TREE-1;anti_count>=0;anti_count--)
    {
        if(shu[anti_count]!=-1)
        {
            return anti_count;
        }
    }
    printf("tail ERROR!\n");
    return 0;
}