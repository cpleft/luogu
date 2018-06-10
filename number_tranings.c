//动态规划dp，经典问题：数字三角形
#include<stdio.h>
int max(int a,int b);
int a[1000][1000],d[1000][1000];
int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            scanf("%d",&a[i][j]);
   for(int i=0;i<n;i++) d[n-1][i]=a[n-1][i];
   for(int i=n-2;i>=0;i--)
       for(int j=0;j<=i;j++)
           d[i][j]=a[i][j]+max(d[i+1][j],d[i+1][j+1]);
    printf("%d\n",d[0][0]);
    return 0;
}
int max(int a,int b){
    return a>b?a:b;
}
