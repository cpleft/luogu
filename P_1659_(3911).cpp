#include<cstdio>
#include<cstring>
using namespace std;

const int MX = 1000 + 10;
float weight[MX], p[MX], loss[MX];
bool book[MX];

int main(void){
    //input
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i = 0; i < N; i++)
        scanf("%f",weight + i);
    for(int i = 0; i < N; i++)
        scanf("%f",p + i);
    weight[N] = 0;

    float ans = 0;
    for(int i = 0; i < K; i++){ // k times
//    printf("Day %d\n", i);
        //for each time find the Maximum profit and the Minimum total loss
        //pretreatment loss[]
        memset(loss, 0, sizeof(loss));
        for(int j = 0; j < N; j++){
            if(book[j]) continue;
            for(int k = 0; k < N; k++){
                if(book[k] || k == j) continue;
                loss[j] += p[k];
            }

//    printf("%.0f ", loss[j]);
        }// loss[j] may == 0
//    printf("\n");

        //find the pig
        //first: the pig must be alive
        float ratio = 0;
        int whichpig = N;//weight[N] == 0;
        for(int j = 0; j < N; j++){
            //weight may == 0; loss[] may == 0;
            if(book[j] || weight[j] == 0) continue;
            if(loss[j] == 0){
                whichpig = j;
                break;
            }

            float temp = weight[j] / loss[j];
            if(temp  > ratio){// why can't temp - ratio > 1e5 ?
                ratio = temp;
                whichpig = j;
            }
        }

//    printf("whichpig = %d\n",whichpig);
        book[whichpig] = 1;
        ans += weight[whichpig];
//    printf("ans = %.0f\n", ans);

        //maintain pigs
        for(int j = 0; j < N; j++){
            weight[j] -= p[j];
            if(weight[j] < 0){
                weight[j] = 0;
                p[j] = 0;
                book[j] = 1;
            }
        }
    }
    //output
    printf("%.0f\n", ans);
    return 0;
}


