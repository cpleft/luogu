// P1071 潜伏者

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int NM = 100000;
char A[NM],B[NM];
char T[NM];
char K[26];

int main(void){
    scanf("%s%s", A, B);
    scanf("%s", T);
    
    memset(K, 0, sizeof(K));
    int n = strlen(A);
    int fl = 0;
//                                    int ans = 0;
    for(int i = 0; i < n; i++){
        if((K[A[i] - 'A'] != 0 && K[A[i] - 'A'] == B[i]) || K[A[i] - 'A'] == 0)
            K[A[i] - 'A'] = B[i];
        else {
            fl = 1;
            break;
        }
 //                               printf("%d\n", n);
  //                              printf("%d\n", ans++);
    }
    // judge if any place is '\0'
//                            printf("%d\n", fl);
    for(int i = 0; i < 26; i++){
 //                           printf("%c ", K[i]);
        if(K[i] == 0) fl = 1;
        for(int j = 0; j < 26; j++)
            if(j != i && K[i] == K[j]) fl = 1;
    }
  //                          printf("\n%d\n", fl);

    if(fl == 1) printf("Failed\n");
    //start translate
    else{
        int m = strlen(T);
        for(int i = 0; i < m; i++){
            T[i] = K[T[i] - 'A'];
            printf("%c", T[i]);
        }
        printf("\n");
    }
    return 0;
}
        





    
