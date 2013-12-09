#include<stdio.h>
#include<ctype.h>
char upper(char c){
    return c-32;
}
int main(){
    char c;
    bool init=true;
    while((c=getchar())!=EOF){
        if(c==' '||c=='\n'){
            init=true;
            putchar(c);
            continue;
        }
        if(init){
            putchar(upper(c));
            init=false;
        }
        else putchar(c);
    }
    return 0;
}

