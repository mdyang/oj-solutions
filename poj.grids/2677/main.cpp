#include<stdio.h>
#include<deque>
using namespace std;
int t;
int matrix[102][102];
int a=0,c=0;
bool is(int i,int j){
    return matrix[i][j]<=50;
}
void count(){
    for(int i=0;i<t;i++)
        for(int j=0;j<t;j++){
            if(is(i,j)){
                a++;
                if((i==0||i==t-1||j==0||j==t-1)||
                        (!is(i-1,j)||!is(i+1,j)||!is(i,j-1)||!is(i,j+1)))c++;
            }
        }
}
int main(){
    scanf("%d",&t);
    for(int i=0;i<t;i++)
        for(int j=0;j<t;j++)
            scanf("%d",&matrix[i][j]);
    count();
    printf("%d %d\n",a,c);
    return 0;
}
