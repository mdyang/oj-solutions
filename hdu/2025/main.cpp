#include<stdio.h>
#include<string.h>
char str[101];
char largest(const char* str,int len){
    char l=str[0];
    for(int i=1;i<len;i++)if(str[i]>l)l=str[i];
    return l;
}
void print(const char* str, int len, char l){
    for(int i=0;i<len;i++){
        printf("%c",str[i]);
        if(str[i]==l)printf("(max)");
    }
}
int main(){
    while(gets(str)){
        int len=strlen(str);
        print(str,len,largest(str,len));
        printf("\n");
    }
    return 0;
}
