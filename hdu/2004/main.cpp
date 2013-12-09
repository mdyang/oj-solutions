#include<stdio.h>
int main(){
    int a;
    while(scanf("%d",&a)!=EOF){
        if (a>=0 && a<=100){
            char grade='E';
            switch(a/10){
                case 10:
                case 9:grade='A';break;
                case 8:grade='B';break;
                case 7:grade='C';break;
                case 6:grade='D';break;
                default:;
            }
            printf("%c\n",grade);
        }
        else{
            printf("Score is error!\n");
        }
    }
    return 0;
}
