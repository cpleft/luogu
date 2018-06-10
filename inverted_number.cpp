//逆序对（归并）
#include<iostream>
#include<algorithm>
using namespace std;

int A[10000];
int T[10000];
int sum=0;
void merge_sort(int*A,int x,int y,int*T){
    if(y-x>1){
        int m=x+(y-x)/2;
        int p=x,q=m,i=x;
        merge_sort(A,x,m,T);
        merge_sort(A,m,y,T);        
        while(p<m||q<y){//将两个有序表合并//求解
            if(q>=y||p<m&&A[p]<A[q]) T[i++]=A[p++];
            else {T[i++]=A[q++];sum+=m-p;}}
        for(int i=x;i<y;i++) A[i]=T[i];
    }
}

int main(void){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];
    merge_sort(A,0,n,T);
    cout<<sum<<endl;
    return 0;
}



