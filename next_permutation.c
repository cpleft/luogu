#include<stdio.h>
#include<algorithm>
using namespace std;
int main(void){
	int n,m;
    int a[10000];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    while(m){
        next_permutation(a,a+n);
        m--;}
    for(int i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    return 0;
}
