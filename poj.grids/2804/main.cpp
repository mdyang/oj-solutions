#include<map>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
char buf[40],w1[20],w2[20];
int main(){
    map<string,string> m;
    while(gets(buf)){
        if(strlen(buf)==0)break;
        sscanf(buf,"%s %s",w1,w2);
        m[string(w2)]=string(w1);
    }
    while(gets(buf)){
        string val=m[string(buf)];
        if(val.size()>0)printf("%s\n",val.c_str());
        else printf("eh\n");
    }

    return 0;
}
