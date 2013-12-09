#include<stdio.h>
#include<string.h>
char s1[101];
char s2[101];
char to_uppercase(char c){
    if(c>='a'&&c<='z')
        return c-'a'+'A';
    return c;
}
void shorten(char* s){
    int i1,i2,len=strlen(s);
    for(i1=i2=0;i1<len;i1++){
        if(s[i1]==' ')continue;
        s[i2++]=to_uppercase(s[i1]);
    }
    s[i2]='\0';
}
bool equal(){
    shorten(s1);
    shorten(s2);
    if(strcmp(s1,s2)==0)return true;
    return false;
}
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(s1);
        gets(s2);
        getchar();
        printf(equal()?"YES\n":"NO\n");
    }
    return 0;
}
