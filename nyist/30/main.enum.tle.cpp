#include<iostream>
#include<limits.h>
using namespace std;
int n;
int t;
int fi[25];
int di[25];
int ti[25];
int current[25];
int curval;
int maxtrace[25];
int maxval;
int fn(int f,int d,int t){
    return f*t-d*t*(t-1)/2;
}
int maxt(int f,int d){
    if(d==0)return INT_MAX;
    return (f+d-1)/d;
}
int fsum(int f,int d,int t){
    //cout<<"fsum(f,d,t)"<<f<<','<<d<<','<<t<<endl;
    if(t==0)return 0;
    if(d==0)return f*t;
    int maxt=(f+d-1)/d;
    if(t<maxt){
        return fn(f,d,t);
    }
    else return fn(f,d,maxt-1)+f-(maxt-1)*d;
}
void judge(){
    if(curval>maxval){
        maxval=curval;
        for(int i=0;i<n;i++)maxtrace[i]=current[i];
    }
}

void go(int i,int t){
    //cout<<"go(i,t)"<<i<<','<<t<<endl;
    // remaining time is not sufficient to go to the next lake, end
    if(t<=ti[i]){
        for(int j=i;j<n;j++)current[j]=0;
        judge();
        return;
    }
    // all lakes have been visited, end
    if(i>=n){
        judge();
        return;
    }
    // subtract time on the road to the next lake from remaining time
    if(i>0)t-=ti[i];
    // action at the next lake
    // the following line will WA
    // for(int j=0;j<=t;i++){
    // but the following line works!
    for(int j=t;j>=0;j--){
        current[i]=j;
        int v=fsum(fi[i],di[i],j);
        //cout<<"fsum="<<v<<endl;
        if(i==0)curval=v;
        else curval+=v;
        go(i+1,t-j);
        curval-=v;
    }
}

void run(){
    while(1){
        cin>>n;
        if(!n)break;
        maxval=0;
        cin>>t;
        t*=12;
        for(int i=0;i<n;i++)cin>>fi[i];
        for(int i=0;i<n;i++)cin>>di[i];
        for(int i=1;i<n;i++)cin>>ti[i];
        go(0,t);
        cout<<maxtrace[0]*5;
        for(int i=1;i<n;i++)cout<<", "<<maxtrace[i]*5;
        cout<<endl;
        cout<<"Number of fish expected: "<<maxval<<endl<<endl;
    }
}
void assert(bool b){
    if(b)cout<<"Assertion succeeded\n";
    else cout<<"Assertion failed\n";
}
void test(){
    /* tests maxt
    assert(maxt(5,2)==3);
    assert(maxt(6,2)==3);
    /* tests fsum
    assert(fsum(9,3,1)==9);
    assert(fsum(9,3,2)==15);
    assert(fsum(9,3,3)==18);
    assert(fsum(9,3,4)==18);
    assert(fsum(7,3,1)==7);
    assert(fsum(7,3,2)==11);
    assert(fsum(7,3,3)==12);
    assert(fsum(7,3,4)==12);
     */

}
int main(){
    test();
    run();
    return 0;
}
