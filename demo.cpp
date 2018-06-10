#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,t,ans,p;
bool f=0;
struct peanuts
{
int x,y,num;
}a[501];//a数组记录有花生的位置 ，x，y为坐标，num花生数量
bool cmp(peanuts a,peanuts b)
{
return a.num>b.num;

}
int main()
{
cin>>n>>m>>t;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
{
int x;
cin>>x;
if(x)//如果这个位置有花生
{
++p;
a[p].x=i;
a[p].y=j;
a[p].num=x;

}
}
}
sort(a+1,a+p+1,cmp);
int tmp=0;//当前消耗的时间
for(int i=1;i<=p;i++)
{
if(i==1)//数量最大的位置，处理方法特殊一点
{
if(tmp+a[i].x+1<=t-a[i].x)//因为最后要求回到路边，所需时间也就是位置坐标x
{
tmp=tmp+a[i].x+1;
ans+=a[i].num;
}
else
{
break;
}
}
    else
{
    int dx=abs(a[i].x-a[i-1].x);
    int dy=abs(a[i].y-a[i-1].y);//坐标的差就是路程，与怎么走无关
if(tmp+dx+dy+1<=t-a[i].x)
{
tmp=dx+dy+tmp+1;
ans+=a[i].num;
}
else
{
break;
}
}
}
cout<<ans;
return 0;
}
