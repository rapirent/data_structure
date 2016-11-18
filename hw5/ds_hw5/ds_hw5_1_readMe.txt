開發平台(Development Platform):win8.1
使用開發環境(Development environment):	minGW & sublime
程式功能(Program Functions):
	此程式可以根據使用者的輸入建造一棵二元搜尋樹，並進而依照使用者選擇的模式來刪除樹中的節點或印出當前的樹
程式設計(Program design):
	
<#define MAX_TREE 1000>
	宣告了一棵樹最多的節點數量
<struct tree…typedef struct tree* tree_pointer;>
	按照課本的方法宣告了樹節點和其指標的型態內容
<void insert(tree_pointer *node,int k);>
	根據傳入的根節點，製造元素k的節點並把它連接在根節點所代表的樹中正確位置上。
	首先以insert_search函式找出k在根節點代表樹的父母節點，若是此節點不存在則將製造的節點接在該位置
	若存在，則比對父母節點和k的值，使k接在正確的位置。
<tree_pointer insert_search(tree_pointer node,int k);>
	將走訪傳入根節點的樹，尋找是否存在k，藉此找到k應當放置的位置，並回傳其父節點
<void delTree(tree_pointer *root,int k);>
	刪除傳入根節點代表的樹中，元素為k之節點。
首先以del_search找出元素k節點和其父節點，並按照此刪除情況分為：
1.	k節點為葉節點
2.	k節點沒有左子節點
3.	k節點沒有右子節點
4.	k節點有左右子節點
的情況來做處理，

如果k節點為葉節點，則直接刪除。若是他沒有左子節點或右子節點，則
判斷是否k節點為根節點，若是根節點，則對應的右左子節點取代它，並調整樹的結構。若不是，則刪除後只做單純結構的調整
	如果k節點有左右子節點，則按照助教所說的競爭規則做刪除
<tree_pointer del_search(tree_pointer nood,int k,tree_pointer*);>
	走訪傳入的根節點代表樹，並找出其中元素為k之節點，並回傳它。除此之外，更以指標得到其父節點。
<void level_order(tree_pointer *);>
	以階層走訪並印出作業要求的印出結果。
	首先以level_order_search得到整棵樹的階層數，並計算出全部該印出的節點數。
	再以一組佇列，以階層方式走訪整棵樹。為了印出X，在遇到樹結構中空節點時，則製造新的節點在此位置上，其元素值為-1，如此在佇列推出該元素時，便可判斷其key值來決定是否印出X
<int level_order_search(tree_pointer node);>
	以遞迴方式走訪一棵樹，當拜訪到葉節點時，回傳1，並每一個階層將此值加一，最後得到根節點左右子樹的階層數，並比對何者較大，傳回最大者（樹之最高階層）

< int main(void)>
	主函式中，先宣告一個字元陣列，以一個迴圈不斷執行scanf來接收每行的輸入（藉此判斷以換行鍵隔開），並之後以strtok函式得到以空白鍵隔開的數字。
	若是使用者輸入E，則馬上呼叫level_order函式，從而印出整棵樹
	若使用者輸入D，則break出此迴圈，進而再以相同方式取得刪除節點
	刪除節點迴圈中，若使用者輸入E，則呼叫level_order函式，從而印出整棵樹
