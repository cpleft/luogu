#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int num;
    int chi,mat,eng;
    int sum;};
struct node stu[300];

bool comp(node p,node q){
    return p.sum>q.sum;}
bool comp1(node p,node q){
    return p.chi>q.chi;}
bool comp2(node p,node q){
    return p.num<q.num;}

int main(void){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>stu[i].chi>>stu[i].mat>>stu[i].eng;
        stu[i].sum=stu[i].chi+stu[i].mat+stu[i].eng;
        stu[i].num=i+1;
    }
    sort(stu,stu+n,comp);
    sort(stu,stu+5,comp2);
    sort(stu,stu+5,comp1);
    sort(stu,stu+5,comp);
    for(int i=0;i<5;i++)
        cout<<stu[i].num<<" "<<stu[i].sum<<endl;
        return 0;
}
