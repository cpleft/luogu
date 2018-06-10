
//归并排序模板

//划分   将序列分成尽量相等的两半  
//递归   将两半元素分别排序
//求解   将两个有序表合并
#include<iostream>
#include<algorithm>
using namespace std;

int A[10000];//存储要排序的数组
int T[10000];//归并排序所需的附加空间

void merge_sort(int*A,int x,int y,int*T){
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



