#include<stdio.h>
#include<string.h>
char strs[10000][55];
int offset[10000];
int main(){
    int c;
    scanf("%d",&c);getchar();
    int max_offset=0;
    for(int i=0;i<c;i++){
        gets(strs[i]);
        int len=strlen(strs[i]);
        for(int j=0;j<len;j++){
            if(strs[i][j]=='.'){
                offset[i]=j;
                if(j>max_offset)max_offset=j;
                break;
            }
        }
    }

    for(int i=0;i<c;i++){
        int j=max_offset-offset[i];
        while(j--)printf(" ");
        printf("%s\n",strs[i]);
    }

    return 0;
}
