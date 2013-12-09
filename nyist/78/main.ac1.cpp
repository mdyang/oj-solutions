#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/*
PointSet[]： 输入的点集
ch[]：输出的凸包的点集，按照逆序输出
n：PointSet中点的数目
len：输出的凸包上的点的个数
*/
struct Point{
    float x,y;
};
//小于说明向量p0p1的极角大于p0p2的极角
float multiply(Point p1,Point p2,Point p0)
{
    return ((p1.x-p0.x)*(p2.y-p0.y) -(p2.x-p0.x)*(p1.y-p0.y));
}
float dis(Point p1,Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x -p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
void Graham_scan(Point PointSet[],Point ch[],int n,int &len)
{
    int i,j,k=0,top = 2;
    Point tmp;
    for (i=1;i<n;i++)
        if ((PointSet[i].y<PointSet[k].y ||((PointSet[i].y==PointSet[k].y)) &&(PointSet[i].x <PointSet[k].x)))
            k=i;
    tmp =PointSet[0];
    PointSet[0]=PointSet[k];
    PointSet[k]=tmp;
    //按极角大小排序
    for (i=1;i<n-1;i++)
    {
        k=i;
        for (j=i+1;j<n;j++)
        {
            if ((multiply(PointSet[j],PointSet[k],PointSet[0])>0)
                ||((multiply(PointSet[j],PointSet[k],PointSet[0])==0)
                && (dis(PointSet[0],PointSet[j]) < dis(PointSet[0],PointSet[k]))))
            {
                tmp = PointSet[j];
                PointSet[j] = PointSet[k];
                PointSet[k] = tmp;
            }
        }
    }
    ch[0] = PointSet[0];
    ch[1] = PointSet[1];
    ch[2] = PointSet[2];
    for (i=3;i<n;i++)
    {
        while (multiply(PointSet[i],ch[top],ch[top-1])>0)
            top--;
        ch[++top] = PointSet[i];
    }
    len = top+1;
}
const int maxN = 1000;
Point PointSet[maxN];
Point ch[maxN];
int n;
int len;
int cmp(const void *a,const void *b)
{
    Point pa = *(Point *)a;
    Point pb = *(Point *)b;
    if (pa.x>pb.x)
        return 1;
    else if((pa.x ==pb.x) &&pa.y>pb.y)
        return 1;
    else return -1;
}
void solve()
{
    int n,i;
    cin>>n;
    for (i=0;i<n;i++)
        cin>>PointSet[i].x>>PointSet[i].y;
    Graham_scan(PointSet,ch,n,len);
    qsort(ch,len,sizeof(ch[0]),cmp);
    for (i=0;i<len;i++)
        cout<<ch[i].x<<" "<<ch[i].y<<endl;
}
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
}