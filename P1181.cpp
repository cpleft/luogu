// 数列分段: 对于给定的一个长度为N的正整数数列A[i]，现要将其分成连续的若干段，并且每段和不超过M（可以等于M），问最少能将其分成多少段使得满足要求。


//下一个元素能加入当前分段就加入

#include<cstdio>
#include<iostream>
using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    int t = 0, ans = 0;
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        if(t == 0 && d <= m) {
            ans ++;
            t = d;
            if( t == m) t = 0;
        }
        else if(d + t < m){
            t += d;
        }
        else if(d + t == m){
            t = 0;
        }
        else {
            ans ++;
            t = d;
        }
    }
    cout << ans <<endl;
    return 0;
}

