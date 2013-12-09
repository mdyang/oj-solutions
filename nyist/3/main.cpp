#include<iostream>
#include<cmath>
#include<iomanip>
const double delta=1e-5;
using namespace std;
int n,m;
double points[10000][2];
double area(double x1,double y1,double x2,double y2){
    return (x1*y2-x2*y1)/2;
}
// weighted center of gravity
double wcogx(double a,double x1,double x2){
    return (x1+x2)*a/3;
}
double wcogy(double a,double y1,double y2){
    return (y1+y2)*a/3;
}
int main(){
    cin>>n;
    while(n--){
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>points[i][0]>>points[i][1];
        }
        double x=0,y=0;
        double asum=0;
        for(int i=0;i<m-1;i++){
            double a=area(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
            x+=wcogx(a,points[i][0],points[i+1][0]);
            y+=wcogy(a,points[i][1],points[i+1][1]);
            asum+=a;
        }
        double a=area(points[m-1][0],points[m-1][1],points[0][0],points[0][1]);
        x+=wcogx(a,points[m-1][0],points[0][0]);
        y+=wcogy(a,points[m-1][1],points[0][1]);
        asum+=a;
        cout<<setiosflags(ios::fixed)<<setprecision(3)<<fabs(asum)<<' ';
        if(fabs(asum)<delta)cout<<"0.000\n";
        else{
            cout<<(x+y)/asum<<endl;
        }
    }
    return 0;
}
