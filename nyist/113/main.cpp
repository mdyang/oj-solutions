#include<string.h>
#include<stdio.h>
char s[1001];
int i;
int len;
void try_replace(){
    if(i+2<len && s[i]=='y' && s[i+1]=='o' && s[i+2]=='u'){
        i+=2;
        printf("we");
    }
    else{
        printf("%c",s[i]);
    }
}
int main(){
    while(gets(s)){
        len=strlen(s);
        for(i=0;i<len;i++){
            if(s[i]=='y')
                try_replace();
            else printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
