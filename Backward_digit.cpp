//数字三角形
#include<iostream>
#include<stdlib.h>
using namespace std;

int n,sum,flag=1;
int book[20],map[20],C[20];

void dfs(int step){
    if(flag==0) return;
    else if(step==1+n){
        for(int i=1;i<=n;i++) C[i]=map[i];
        for(int i=2;i<=n;i++)
            for(int j=1;j<=n-i+1;j++)
                C[j]=C[j]+C[j+1];
        if(C[1]==sum&&flag==1) {
            for(int i=1;i<=n;i++) cout<<map[i]<<" ";
            flag=0;
        }
    }

    else for(int i=1;i<=n;i++){
        if(book[i]==0){
            book[i]=1;
            map[step]=i;
            dfs(step+1);
            book[i]=0;
        }
    }

}

int main(void){
    cin>>n>>sum;
    dfs(1);
    return 0;}
