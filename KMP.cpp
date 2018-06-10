#include<cstdio>
#include<cstring>
using namespace std;

const int NM = 1000000 + 20;
char s1[NM], s2[NM];
int Next[NM];

void Pretreat(void){
    memset(Next, 0, sizeof(Next));
    int m = strlen(s2);
    Next[0] = Next [1] = 0;
    int j = 0;
    for(int i = 2; i < m; i++){
        while(j > 0 && s2[j + 1] != s2[i])
            j = Next[j];
        if(s2[j + 1] == s2[i])
            j += 1;
        Next[i] = j;
    }
    return;
}

void KMP(void){
    int n = strlen(s1);
    int m = strlen(s2);
    int k = 0;
    for(int i = 1; i < n; i++){
        while(k > 0 && s2[k + 1] != s1[i])
            k = Next[k];
        if(s2[k + 1] == s1[i])
            k += 1;
        if(k == m - 1){
            printf("%d\n", i - m + 2);
            k = Next[k];
        }
    }
}

int main(void){
    scanf("%s%s", s1 + 1, s2 + 1);
    s1[0] = s2[0] = '0';
    
    Pretreat();
    KMP();
    //output, Next
    for(int i = 1; i < strlen(s2); i++)
        printf("%d ", Next[i]);
    printf("\n");
    return 0;
}
