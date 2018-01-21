# 难度较大>< ~~但可以取巧~~。

## 题目：
> 题目描述  
因为151既是一个质数又是一个回文数(从左到右和从右到左是看一样的)，所以 151 是回文质数。  
写一个程序来找出范围[a,b](5 <= a < b <= 100,000,000)( 一亿)间的所有回文质数;  
输入输出格式  
输入格式：  
第 1 行: 二个整数 a 和 b .  
输出格式：  
输出一个回文质数的列表，一行一个。

## 分析：
- 最大值为1亿。。暴力循环会超时。
- 经过简单的分析，一位数和两位数的回文，且是质数的很少， 直接判断输入长度 打表输出即可。 可以省出很多时间。
- 参考代码中生成回文的方法。


## 代码：
```cpp
#include<bits/stdc++.h>
using namespace std;
bool ispr(int n)
{
    for(int k=2;k<=sqrt(n);++k)
    if(n%k==0)
    return false;
    return true;
}
int getsize(int n)
{
    int m=1,k=n;
    while(k>9)
    {
        k/=10;
        ++m;
    }
    return m;
}
int main()
{
    int l,m,n,q,w,i,j,k;
    cin>>m>>n;
    q=getsize(m);
    w=getsize(n);
    if(q<=1&&w>=1)
    {
        if((m<=5)&&(n>=5))
        cout<<5<<endl;
        if((m<=7)&&(n>=7))
        cout<<7<<endl;
    }
    if((q<=2)&&(w>=2))
    {
        if((m<=11)&&(n>=11))
        cout<<11<<endl;
    }
    if((q<=3)&&(w>=3))
    {
        for(int a=1;a<=9;a+=2)
        for(int b=0;b<=9;++b)
        {
            int f=a*100+b*10+a;
            if(f<m)
            continue;
            if(f>n)
            return 0; 
            if(ispr(f))
            cout<<f<<endl;
        }
    }
    if((q<=5)&&(w>=5))
    {
        for(int a=1;a<=9;a+=2)
        for(int b=0;b<=9;++b)
        for(int c=0;c<=9;++c)
        {
            int f=a*10000+b*1000+c*100+b*10+a;
            if(f<m)
            continue;
            if(f>n)
            return 0; 
            if(ispr(f))
            cout<<f<<endl;
        }
    }
    if((q<=7)&&(w>=7))
    {
        for(int a=1;a<=9;a+=2)
        for(int b=0;b<=9;++b)
        for(int c=0;c<=9;++c)
        for(int d=0;d<=9;++d)
        {
            int f=a*1000000+b*100000+c*10000+d*1000+c*100+b*10+a;
            if(f<m)
            continue;
            if(f>n)
            return 0; 
            if(ispr(f))
            cout<<f<<endl;
        }
    }
    return 0;
}
```

### 洛谷大佬：
> 本题难度相对比较大，核心思路：利用题目给的回文数方法列出所有回文数，再判断是否为质数。

> 步骤：

> 1）输入m,n后，编写一个函数求m,n的位数以决定以下操作哪些可以全部跳过，哪些操作至少要做一部分。

> 2）1位回文质数只有5,7；2位回文质数只有11。因此此部分可以直接打表。

> 3）可以证明不存在4,6,8位（以及更大偶数位）的回文质数。这一点可以通过一个完全枚举回文质数的程序运行结果证实。因此此部分可以忽略。

> 4）9位数最多只有100000000一个数，而且不是回文质数。因此此部分可以忽略。

> 5）注意每一个打表或构造得到的回文数，要判断是否在闭区间[m,n]内。小于m就continue，大于n就return 0（因为此后所有数一定都大于n）。

> 6）每个经过上述四步得到的回文数，输出并换行即可。

> AC代码（C++）（看起来比较繁琐，但每一步都独立而清晰【自吹中……】）

