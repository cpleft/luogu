// greedy

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int M = 5000 + 100;
struct node{
    int p; //price
    int q; //quantity
};
struct node que[M];
bool cmp(node x, node y){
    return x.p < y.p;
}

int main(void){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> que[i].p >> que[i].q;
    }
    sort(que, que + m, cmp);
    int ans = 0, amount = 0;
    int k = 0;
    while(amount < n){
        if(amount + que[k].q <= n){
            ans += que[k].q * que[k].p;
            amount += que[k].q;
        }
        else {
            ans += que[k].p * (n - amount);
            amount = n;
        }
        k++;
    }
    cout << ans << endl;
    return 0;
}
