Program Enviroment:

IDE: dev-C++
OS: win8.1
Compiler: GCC

Program Description:

<main>

inputa,inputb:存取輸入資料
while 迴圈:判斷資料是否正確,不會出現第二個輸入值大過第一個輸入值的狀況

iterative答案透過呼叫iterahsuen而得
recursive答案透過呼叫recurchie而得 

<recurhsuen>

由課本上的公式知道C(n,m)=C(n-1,m)+C(n-1,m-1),觀察此式可知此關係將會在m=1時或n=m時收斂
故設定m=1或n=m時回傳n/m

<iterahsuen>
由二項式係數的基本概念得知,C(n,m)=n!/(m!(n-m)!)
直觀地算出各階層並做乘除運算後而得