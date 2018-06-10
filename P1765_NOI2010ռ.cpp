#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstring>
using namespace std;
char s1[]={" adgjmptw"},s2[]={"behknqux"},s3[]={"cfilorvy"},s4[]={"sz"};
int main(void){
    char c;
    int s=0;
    while((c=getchar())!=EOF){
        if(strchr(s1,c)) s++;
        if(strchr(s2,c)) s+=2;
        if(strchr(s3,c)) s+=3;
        if(strchr(s4,c)) s+=4;
    }
    cout<<s<<endl;
    return 0;
}
