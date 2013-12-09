#include<stdio.h>
int notes[5]={100,50,10,5,2};
int note_count(int salary){
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=salary/notes[i];
        salary%=notes[i];
    }
    sum+=salary;
    return sum;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n>0){
        int sum=0,temp;
        while(n--){
            scanf("%d",&temp);
            sum+=note_count(temp);
        }
        printf("%d\n",sum);
    }
    return 0;
}
