#include<stdio.h>
char s[4];
void comp_swap(char*a,char*b){
    if(*a>*b){
        char temp=*a;
        *a=*b;
        *b=temp;
    }
}
int main(){
    while(scanf("%s",s)!=EOF){
        comp_swap(&s[0],&s[1]);
        comp_swap(&s[1],&s[2]);
        comp_swap(&s[0],&s[1]);
        printf("%c %c %c\n",s[0],s[1],s[2]);
    }
    return 0;
}
