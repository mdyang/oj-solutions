#include<stdio.h>
#include<cstring>
#include<string>
#include<map>
using namespace std;
char buf[1024];
char standard[8];
int m[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
bool is(char c){
    if((c>='0'&&c<='9')||(c>='A'&&c<='Z'))return true;
    return false;
}
string parse(char* s){
    int i=0,j=0;
    int len=strlen(s);
    for(;i<len;i++){
        if(is(s[i])){
            if(isdigit(s[i]))
                standard[j++]=s[i];
            else standard[j++]=m[s[i]-'A']+'0';
        }
    }
    return string(standard);
}
int main(){
    standard[7]='\0';
    int t;
    map<string,int> book;
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(buf);
        string s=parse(buf);
        int c=book[s];
        book[s]=c+1;
    }
    bool dup=false;
    for(map<string,int>::iterator i=book.begin();i!=book.end();i++){
        string str=i->first;
        int c=i->second;
        if(c>1){
            dup=true;
            printf("%s-%s %d\n",str.substr(0,3).c_str(),str.substr(3,7).c_str(),c);
        }
    }
    if(!dup){
        printf("No duplicates.\n");
    }
    return 0;
}
