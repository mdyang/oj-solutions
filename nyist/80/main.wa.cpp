#include<stdio.h>
int r[5]={1,8,28,56,70};
int main(){
    char a[3];
    int n=1;
    while(~scanf("%s",a)){
        int i=0,c=0;
        do{
            for(int j=0;j<3;j++)
                if(a[j]=='B')c++;
            if(++i>2)break;
            scanf("%s",a);
        }while(1);
        if(c>4)c=8-c;
        printf("Case %d: %d\n",n++,r[c]);
    }
    return 0;
}
