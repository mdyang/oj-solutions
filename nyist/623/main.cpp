#include <stdio.h>

int a[50][50];
int b[50][50];
int r[50][50];

int main(){

    int m,n,k;
    while(1){
        scanf("%d%d%d", &m, &n, &k);
        if ((m|n|k)==0) break;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);

        for(int i=0;i<n;i++)
            for(int j=0;j<k;j++)
                scanf("%d",&b[i][j]);

        for(int i=0;i<m;i++){
            for(int j=0;j<k;j++){
                int s=0;
                for(int l=0;l<n;l++)
                    s+=a[i][l]*b[l][j];
                r[i][j]=s;
            }
        }

        for (int i=0;i<m;i++){
            for(int j=0;j<k;j++)
                printf("%d ",r[i][j]);
            printf("\n");
        }
            
    }

    return 0;
}
