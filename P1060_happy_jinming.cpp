//开心的金明

//动态规划   0 1 背包问题

#include<cstdio>
#include<algorithm>

const int MX = 50;
int v[MX],p[MX];//v price_of_item    p importance_of_item

int main(void){
    int N,M;//N money  M number_of_items
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d%d",&v[i],&p[i]);
    }
    


