#include<stdio.h>
#include<string.h>
int score1[100000][2];
int score2[100000][2];
int main(void){
    char c;
    int x=0,y=0,i=0,j=0,p=0,q=0;
    while((c=getchar())!='E'){
       if(c=='W') x++;
       if(c=='L') y++;
       if(x==11&&y<=9||y==11&&x<=9||x>=10&&y>=10&&x-2==y||x>=10&&y>=10&&y-2==x){
           score1[i][0]=x;       
           score1[i][1]=y;
           i++;
           x=y=0;}
       if(c=='W') p++;
       if(c=='L') q++;
        if(p==21&&q<=19||q==21&&p<=19||p>=20&&q>=20&&p-2==q||p>=20&&q>=20&&q-2==p){
           score2[j][0]=p;       
           score2[j][1]=q;
           j++;
           p=q=0;}
 
    }
    for(int a=0;a<i;a++)
         printf("%d:%d\n",score1[a][0],score1[a][1]);
    printf("%d:%d\n\n",x,y);
    for(int a=0;a<j;a++)
         printf("%d:%d\n",score2[a][0],score2[a][1]);
    printf("%d:%d\n",p,q); 
    return 0;
}
