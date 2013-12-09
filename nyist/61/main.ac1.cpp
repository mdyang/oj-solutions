#include <cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int v[52][52];
int f[102][52][52];
int main()
{  
    int T,m,n,c,t;
    scanf("%d",&T);
    while(T--)
    {   
        memset(v,0,sizeof(v));
        memset(f,0,sizeof(f));
        scanf("%d%d",&m,&n);
        c=m+n-2;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&v[i][j]);
        for(int k=1;k<c;k++)
        {
            t=k+2>m?m:k+2;
            for(int i=1;i<=t;i++)
                for(int j=i+1;j<=t;j++)
                    if(i!=j) //¶àÓà£¿
                        f[k][i][j]=max(
                            max(f[k-1][i-1][j],
                                f[k-1][i][j-1]),
                            max(f[k-1][i][j],
                                f[k-1][i-1][j-1]))
                            +v[i][k-i+2]+v[j][k-j+2];
            }
        f[c][m][m]=max(f[c-1][m-1][m],f[c-1][m][m-1]);
        printf("%d\n",f[c][m][m]);
    }
    return 0;
}