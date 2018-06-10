#include<iostream>
#include<algorithm>
using namespace std;
       
struct node{
    int num;
    int sum;
    int pow;};
struct node stu[200000];

bool comp(node p,node q){
    return p.sum>q.sum;}
bool comp_(node p,node q){
    return p.num<q.num;}
int N,R,Q;

void merge_sort(node*A,int x,int y,node*T){
    if(y-x>1){
        int m=x+(y-x)/2;
        int p=x,q=m,i=x;
        merge_sort(A,x,m,T);
        merge_sort(A,m,y,T);        
        while(p<m||q<y){//将两个有序表合并//求解
            if(q>=y||A[p]<A[q]) T[i++]=A[p++];
            else T[i++]=A[q++];}
        for(int i=x;i<y;i++) A[i]=T[i];
    }
}

int main(void){
    cin>>N>>R>>Q;
    for(int i=0;i<2*N;i++){
        cin>>stu[i].sum;
        stu[i].num=i+1;}
    for(int i=0;i<2*N;i++)
        cin>>stu[i].pow;
    sort(stu,stu+2*N,comp_);
    sort(stu,stu+2*N,comp);

    merge_sort(

    cout<<stu[Q-1].num<<endl;
    return 0;
}




/*
#include<iostream>
#include<algorithm>
using namespace std;
       
struct node{
    int num;
    int sum;
    int pow;};
struct node stu[200000];

bool comp(node p,node q){
    return p.sum>q.sum;}
bool comp_(node p,node q){
    return p.pow>q.pow;}

int main(void){
    int N,R,Q;
    cin>>N>>R>>Q;
    for(int i=0;i<2*N;i++){
        cin>>stu[i].sum;
        stu[i].num=i+1;}
    for(int i=0;i<2*N;i++)
        cin>>stu[i].pow;
    sort(stu,stu+2*N,comp);
    for(int i=0;i<R;i++){
        for(int j=0;j<N-1;j+=2)
            sort(stu+j,stu+j+2,comp_);
        sort(stu,stu+2*N,comp);
    }
    cout<<stu[Q-1].num<<endl;
    return 0;
}
*/
