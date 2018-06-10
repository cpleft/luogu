// compare the first few bit size
/*

cmp 用法不对？？？

#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int M = 20 + 5;
int arr[M];

bool cmp(int x, int y){
    int n = 0, m = 0;
    int a[100], b[100];
    while(x){
        x /= 10;
        n++;
    }
    while(y){
        y /= 10;
        m++;
    }
    
    int j = n, k = m;
    for(int i = 0; i < n; i++){//n 位数
        a[i] = (int)(x / pow(10, j - 1)) % 10;
        j--;
    }
    for(int i = 0; i < m; i++){
        b[i] = (int)(y / pow(10, k - 1)) % 10;
        k--;
    }

    for(int i = 0; i < min(n, m); i++){
        if(a[i] == b[i]) continue;
        else return a[i] > b[i];
    }

    // if the first few bit of the two numbers are equal, return one of the two
    return x > y;
}
        
int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);

    sort (arr, arr + n, cmp);
    
    for(int i = 0; i < n; i++)
        printf("%d", arr[i]);
    printf("\n");
    return 0;
}
*/


#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int M = 100;
string a[M];

bool cmp(string x, string y){
    return x + y > y + x;
}

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n, cmp);

    for(int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;
    return 0;
}
