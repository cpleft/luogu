#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct node{
    int x;
    int y;
    int s;};
int M,N,K;
int tl=0;
struct node queue[1000];
int map[20][20];
void change(node p,node q);
bool comp(node p,node q);
int main(void){
    scanf("%d%d%d",&M,&N,&K);
    int head=0,tail=0;
    int sum=0;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j]); 
            if(map[i][j]){
                queue[tail].x=i;
                queue[tail].y=j;
                queue[tail].s=map[i][j];
                tail++;}
        }
    sort(queue,queue+tail,comp);
    K-=queue[head].x+1+1;
    tl+=queue[head].x+1;
    if(K-tl>=0) sum+=queue[head].s;
    else{
        printf("%d\n",sum);
        return 0;} 
    head++;
    while(head<tail){
        change(queue[head],queue[head-1]);
        if(K-tl>=0) sum+=queue[head].s;
        else{
            printf("%d\n",sum);
            return 0;}
        head++;    
    }
    printf("%d\n",sum); 
    return 0;
}
void change(node p,node q){
    if(p.x>q.x) tl+=abs(q.x-p.x);
    else tl-=abs(q.x-p.x);
    K-=abs(q.x-p.x);
    K-=abs(q.y-p.y);
    K--;}
bool comp(node p,node q){
    return p.s>q.s;
}
