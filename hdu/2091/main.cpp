#include<stdio.h>
int main(){
    char c;
    int n;
    bool first=true;
    while(1){
        scanf("%c",&c);
        if(c=='@')break;
        scanf("%d\n",&n);
        if(first)first=false;
        else printf("\n");
        if (n==1) printf("%c\n",c);
        else{
        for(int j=0;j<n-1;j++)printf(" ");
        printf("%c\n",c);
        for(int i=1;i<n-1;i++){
            for(int j=0;j<n-i-1;j++)printf(" ");
            printf("%c",c);
            for(int j=0;j<2*i-1;j++)printf(" ");
            printf("%c\n",c);
        }
        for(int i=0;i<2*n-1;i++)printf("%c",c);
        printf("\n");
        }
    }
    return 0;
}
