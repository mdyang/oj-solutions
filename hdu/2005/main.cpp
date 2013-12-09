#include<stdio.h>
bool leap(int y){
    if(y%400==0)return true;
    if(y%100 && y%4==0)return true;
    return false;
}
int sofar[11]={31,59,90,120,151,181,212,243,273,304,334};
int main(){
    int y,m,d;
    while(scanf("%d/%d/%d",&y,&m,&d)!=EOF){
        int days=m>1?sofar[m-2]+d:d; 
        if(leap(y)&&m>2)days++;
        printf("%d\n",days);
    }
    return 0;
}
