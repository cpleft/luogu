#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    string name;
    int fexamscore;
    int classscore;
    char IfLeader;
    char IfWest;
    int thesisnum;
    int sum;};
struct node student[100];

void scholar(node *x){
    if(x->fexamscore>80&&x->thesisnum>=1) x->sum+=8000;
    if(x->fexamscore>85&&x->classscore>80) x->sum+=4000;
    if(x->fexamscore>90) x->sum+=2000;      //x-> 相当于 (*x).
    if(x->fexamscore>85&&x->IfWest=='Y') x->sum+=1000;
    if(x->classscore>80&&x->IfLeader=='Y') x->sum+=850;
    return;
}

bool comp(node p,node q){
    return p.sum>q.sum;
}

int main(void){
    int N,ans=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        cin>>student[i].name>>student[i].fexamscore>>student[i].classscore>>student[i].IfLeader>>student[i].IfWest>>student[i].thesisnum;
        scholar(&student[i]);//
        ans+=student[i].sum;}
    sort(student,student+N,comp);
    cout<<student[0].name<<endl<<student[0].sum<<endl<<ans;
    return 0;
}
