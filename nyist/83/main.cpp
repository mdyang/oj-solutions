#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
struct point{
    double x;
    double y;
};
struct line{
    point a;
    point b;
};
line lines[30];
int n;
double l[30],t[30],r[30],d[30],x,y;
int lc,tc,rc,dc;
void dispatch(point p){
    if(p.x==0){ // left
        l[lc++]=p.y;
        return;
    }
    if(p.x==100){ // right
        r[rc++]=p.y;
        return;
    }
    if(p.y==0){ // down
        d[dc++]=p.x;
        return;
    }
    if(p.y==100){ // top
        t[tc++]=p.x;
        return;
    }
}
bool intersect(line &l,point& a,point& b){
    double x=l.b.x-l.a.x;
    double y=l.b.y-l.a.y;
    double r1=(a.x-l.a.x)*y-(a.y-l.a.y)*x;
    double r2=(b.x-l.a.x)*y-(b.y-l.a.y)*x;
    if((r1>0&&r2<0)||(r1<0&&r2>0))return true;
    return false;
}
int scan(double x1,double y1){
    int temp=0;
    point a,b;
    a.x=x;a.y=y;
    b.x=x1;b.y=y1;
    for(int i=0;i<n;i++)
        if(intersect(lines[i],a,b))temp++;
    return temp;
}
int main(){
    int _t;
    scanf("%d",&_t);
    while(_t--){
        lc=tc=rc=dc=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf %lf %lf %lf",
                    &lines[i].a.x,
                    &lines[i].a.y,
                    &lines[i].b.x,
                    &lines[i].b.y);
            dispatch(lines[i].a);
            dispatch(lines[i].b);
        }
        scanf("%lf %lf",&x,&y);
        sort(l,l+lc);
        sort(r,r+rc);
        sort(d,d+dc);
        sort(t,t+tc);
        int count=INT_MAX,temp;
        // top
        if(t[0]>0){
            temp=scan(t[0]/2,100);
            if(temp<count)count=temp;
        }
        for(int i=0;i<tc-1;i++){
            temp=scan((t[i]+t[i+1])/2,100);
            if(temp<count)count=temp;
        }
        if(t[tc-1]<100){
            temp=scan((t[tc-1]+100)/2,100);
            if(temp<count)count=temp;
        }
        // down
        if(d[0]>0){
            temp=scan(d[0]/2,0);
            if(temp<count)count=temp;
        }
        for(int i=0;i<dc-1;i++){
            temp=scan((d[i]+d[i+1])/2,0);
            if(temp<count)count=temp;
        }
        if(d[dc-1]<100){
            temp=scan((d[dc-1]+100)/2,0);
            if(temp<count)count=temp;
        }
        // left
        if(l[0]>0){
            temp=scan(0,l[0]/2);
            if(temp<count)count=temp;
        }
        for(int i=0;i<lc-1;i++){
            temp=scan(0,(l[i]+l[i+1])/2);
            if(temp<count)count=temp;
        }
        if(l[lc-1]<100){
            temp=scan(0,(l[lc-1]+100)/2);
            if(temp<count)count=temp;
        }
        // right
        if(r[0]>0){
            temp=scan(100,r[0]/2);
            if(temp<count)count=temp;
        }
        for(int i=0;i<rc-1;i++){
            temp=scan(100,(r[i]+r[i+1])/2);
            if(temp<count)count=temp;
        }
        if(r[rc-1]<100){
            temp=scan(100,(r[rc-1]+100)/2);
            if(temp<count)count=temp;
        }
        printf("%d\n",count+1);
    }
    return 0;
}
