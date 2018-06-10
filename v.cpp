




#include <bits/stdc++.h>
#define ll long long
#define pi acos(-1)
#define inf 0x3f3f3f3f//0x7fffffff
using namespace std;

int dirx[4] = {-1,1,0,0};//four directions
int diry[4] = {0,0,-1,1};//four directions
int dix[8]={0,0,-1,1,1,1,-1,-1};//eight directions
int diy[8]={1,-1,0,0,-1,1,-1,1};//eight directions
const int maxn=0;
const int M = 7;
struct Matrix
{
    int matrix[3][3];
};
Matrix mul(Matrix A,Matrix B)
{
    Matrix C;
    for(int i = 1; i <= 2; ++i)
        for(int j = 1; j <= 2; ++j)
            C.matrix[i][j] = 0;
    for(int i = 1; i <= 2; ++i)
        for(int k = 1; k <= 2; ++k)
            for(int j = 1; j <= 2; ++j)
                C.matrix[i][j] = (C.matrix[i][j] + A.matrix[i][k] * B.matrix[k][j]) % M;
    return C;
}
Matrix QuickPower(Matrix A,int n)
{
    Matrix ans;
    if(n == 1)
        return A;
    ans = QuickPower(A,n/2);
    ans = mul(ans,ans);
    if(n & 1)
        ans = mul(ans,A);
    return ans;
}
int main(void)
{
    //freopen("in.txt","r",stdin);
    int a,b,n;
    Matrix mat,ans;
    while(scanf("%d%d%d",&a,&b,&n))
    {
        if(a == 0 && b == 0 && n == 0)
            return 0;
        mat.matrix[1][1] = 0;
        mat.matrix[1][2] = b;
        mat.matrix[2][1] = 1;
        mat.matrix[2][2] = a;

    /*
        ans = mul(mat, mat);
        for(int i = 1; i <= 2; i++){
            for(int j = 1; j <= 2; j++)
                printf("%d ", ans.matrix[i][j]);
            printf("\n");
        }
        */
        ans = QuickPower(mat,n-2);
        cout<<ans.matrix[1][1]<<' '<<ans.matrix[1][2]<<endl<<ans.matrix[2][1]<<' '<<ans.matrix[2][2]<<endl;
        //printf("%d\n",ans.matrix[1][1] + ans.matrix[2][1]);
    }
    return 0;
}
