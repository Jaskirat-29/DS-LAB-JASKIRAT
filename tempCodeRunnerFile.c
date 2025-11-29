#include<stdio.h>
void toh( int n,char s, char m,char d){
    if(n==1){
        printf("move disk from %c to %c\n",s,d);
    }
    else{
        toh(n-1,s,d,m);
        printf("move disk from %c to %c\n",s,d);
        toh(n-1,m,s,d);
    }

}
int main(){
    int a;
    printf("enter no.of disks:");
    scanf("%d",&a);
    char S='s';
    char M='m';
    char D='d';
    toh(a,S,M,D);
}