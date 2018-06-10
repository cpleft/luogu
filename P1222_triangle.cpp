#include<stdio.h>
using namespace std;
int map[2000][2000],book[2000][2000];

int main(void){
    int n,xi,yi,m;
    int sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&xi,&yi,&m);
        sum+=m*m/2;
