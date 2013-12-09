#include<stdio.h>
#include<string.h>
#define M 1010
char str[M],*pstr[M];
int zuo[M],you[M],op[M],nc,pn,n;
int buildtree(int x=0,int y=strlen(str)-1)
{
    int u,i,c1=-1,c2=-1,p=0,ismun=1;
    for(i=x;i<y;i++)
    {
        switch(str[i])
        {
            case '(':p++;ismun=0;break;
            case ')':p--;ismun=0;break;
            case '+':case '-':ismun=0;if(p==0)c1=i;break;
            case '*':case '/':ismun=0;if(p==0)c2=i;break;
        }
    }
    if(ismun)
    {
        pstr[pn++]=str+x;
        return(n--);
    }
    if(c1<0)c1=c2;
    if(c1<0)return(buildtree(x+1,y-1));
    u=++nc;
    zuo[u]=buildtree(x,c1);
    you[u]=buildtree(c1+1,y);
    op[u]=str[c1];
    return(u);
}
float findtree(int n=1)
{
    float a,b;
    if(zuo[n]>0)a=findtree(zuo[n]);
    else sscanf(pstr[-zuo[n]],"%f",&a);
    if(you[n]>0)b=findtree(you[n]);
    else sscanf(pstr[-you[n]],"%f",&b);
    switch(op[n])
    {
        case '*':return(a*b);
        case '/':return(a/b);
        case '+':return(a+b);
        case '-':return(a-b);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        nc=pn=n=0;
        scanf("%s",str);
        buildtree();
        printf("%.2lf\n",findtree());
    }
    return(0);
}
