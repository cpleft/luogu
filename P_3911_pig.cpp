// 养猪 贪心

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int MX = 10000;
int weight[MX],p[MX];
bool book[MX];
int loss[MX];

int main(void){
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i = 0; i < N; i++)
        scanf("%d",weight + i);
    for(int i = 0; i < N; i++)
        scanf("%d",p + i);

    int ans = 0;
    for(int i = 0; i < K; i++){//  k times
        //for each time find the Maximum profit and the Minimum total loss

        //pretreatment loss[]
        memset(loss, 0, sizeof(loss));
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(book[j]) break;
                if(book[k] || k == j) continue;
                loss[j] += p[k];
            }
        }

        //find the pig
        float ratio = weight[0] / loss[0];
        int WhichPig;
        for(int j = 0; j < N; j++){
            if(loss[j] == 0) {
                WhichPig = j;
                break;
            }
            if(book[j] == 1) continue;
            float temp = weight[j] / loss[j];
            if(temp - ratio > 1e-5){
                ratio = temp;
                WhichPig = j;
            }
        }
        book[WhichPig] = 1;
        ans += weight[WhichPig];

        //maintain pigs
        for(int k = 0; k < N; k++){
            if(p[k] > weight[k]) p[k] = weight[k];//maintain p[i]
            weight[k] -= p[k];
            if(weight[k] == 0) book[k] = 1;
        }
    }
    
    //output
    printf("%d\n",ans);
    return 0;
}

