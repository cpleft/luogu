//it isn't water!!!

#include<cstdio>
#include<climits>
#include<iostream>
#include<algorithm>
using namespace std;

/*
practice 1:
1. every time take two smaller ones, merge them.
2. repeat step 1 until there only one left.

*/

int function1(int arr[], int n){
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        //
        sort(arr, arr + n);

        ans += arr[0] + arr[1];
        arr[0] = arr[0] + arr[1];
        arr[1] = INT_MAX;
    }
    return ans;
}

/*
practice 2:
insertion sort
1. sort the array, find two smaller number.
2. insert the merged number into the array.(has orderd)


insertion sort:

void insertion_sort(int arr[], int len){
    for(int i = 1; i < len; i++){
        int temp = arr[i];
        int j = i - 1;
        for(; j >= 0 && arr[j] > temp; j--){// ascending order
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

dichotomous insertion sort


*/
bool cmp(int x, int y){
    return x > y;
}

int function2(int arr[], int len){
    int ans = 0;

    // descending sort
    sort(arr, arr + len, cmp);
    for(int i = len - 1; i > 0; i--){
        ans += arr[i] + arr[i - 1];
        arr[i - 1] += arr[i];
        arr[i] = 0;//0 or MAX 
        int temp = arr[i - 1];
        int j = i - 2;
        while(j >= 0 && temp > arr[j]){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        /*
        for(int k = 0; k < i; k++)
            printf("%d ", arr[k]);
        pintf("\n");
        */
    }
    return ans;
}

/*
practice 3:
pq P_Q  priority queue
1. push all elements into pq
2. every time pop the top two elements and add them then push it.
3. until only two elements left,(add them)

c++ STL template

*/


#include<queue>

//priority from small to large
priority_queue<int, vector<int>, greater<int> > Arr;

int function3(int arr[], int len){
    int ans = 0;
    for(int i = 0; i < len; i++){
        Arr.push(arr[i]);
    }
    for(int i = 1; i < len; i++){
        int temp = 0;
        temp += Arr.top();
        Arr.pop();
        temp += Arr.top();
        Arr.pop();
        ans += temp;
        Arr.push(temp);
    }
    return ans;
}

/*
practice 4:
create a heap ///like the priority queue but faster(is it? Y. 4 times)

*/


/*********************************************************

//use array. Must start with NO.1

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

void shiftdown(int i);
void shiftup(int i);
void hs();
void build();
int deletemin();
void swap(int i, int j);

//It is a minimum heap.

int n;//size of heap, from 0 on
const int M = 100000 + 100;
int heap[M];//use array. Must start with NO.1

//to delete
void shiftdown(int i){//from point to start
    int flag = 0, t;
    while(flag == 0 && 2 * i <= n){
        //left subtree
        if(heap[i] > heap[2 * i])
            t = 2 * i;
        else t = i;

        //right subtree
        if(i * 2 + 1 <= n){
            if(heap[t] > heap[2 * i + 1])
                t = 2 * i + 1;
        }

        //
        if(t != i){
            swap(i, t);
            i = t;
        }
        else flag = 1;
    }

}

//to insert
void shiftup(int i){
    if(i == 1) return;
    int flag = 0;

    while(i != 1 && flag == 0){
        if(heap[i] < heap[i / 2]){
            swap(i, i / 2);
            i = i / 2;
        }
        else flag = 1;
    }
}

int deletemin(){
    int t;
    t = heap[1];

    heap[1] = heap[n];
    n--;
    shiftdown(1);

    //return the minium number
    return t;
}


void swap(int i, int j){
    int temp;
    temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;

    return;
}
    
void build(){
    //从最后一个非叶节点开始依次向下调整
    for(int i = n / 2; i > 0; i--){
        shiftdown(i);
    }
    return;
}

//heap sort
void hs(){
    while(n > 1){
        //pop
        swap(1, n);
        n--;
        shiftdown(1);
    }
    return;
}


int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> heap[i];
    heap[0] = 0;

    int num = n;
    //
    build();

    int ans = 0;
    for(int i = 2; i <= num; i++){
        int temp = 0;
        temp += deletemin();
        temp += deletemin();
        ans += temp;
        heap[n + 1] = temp;
        shiftup(n + 1);
        n++;
    }
    printf("%d\n", ans);

    return 0;
}




****************************************************/


const int M = 10000 + 100;
int arr[M];

int main(void){
    //input
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    //function:


    cout << functionx(arr, n) << endl;
    return 0;
}

