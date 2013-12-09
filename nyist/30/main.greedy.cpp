#include<iostream>
using namespace std;
int curval,maxval;
int f[25],d[25],t[25];
int n,h;
int main(){
    t[0]=0;
    while(1){
        cin>>n;
        if(!n)break;
        cin>>h;
        h*=12;
        for(int i=0;i<n;i++)cin>>f[i];
        for(int i=0;i<n;i++)cin>>d[i];
        for(int i=1;i<n;i++)cin>>t[i];
        int max_val=0;
        int max_trace[25];
        // lake i as the last lake
        for(int i=0;i<n;i++){
            int temp_trace[25]={0};
            int _f[25];
            for(int j=0;j<n;j++)_f[j]=f[j];
            int _t=h;
            // subtract the time on the road from total time
            for(int j=0;j<=i;j++)_t-=t[j];
            if(_t<=0)break;
            int temp_val=0;
            // fish!
            while(_t){
                int _i=0,_fi=0;
                // find the current most fish-abundant lake _i
                for(int j=0;j<=i;j++)
                    if(_f[j]>_fi){
                        _fi=_f[j];
                        _i=j;
                    }
                // no more fish
                if(!_fi){
                    temp_trace[0]+=_t;
                    break;
                }
                temp_val+=_fi;
                temp_trace[_i]++;
                // decrease fish in lake _i
                _f[_i]-=d[_i];
                if(d[_i]<0)d[_i]=0;
                _t--;
            }
            if(temp_val>max_val){
                max_val=temp_val;
                for(int i=0;i<n;i++)max_trace[i]=temp_trace[i];
            }
        }
        cout<<max_trace[0]*5;
        for(int i=1;i<n;i++)cout<<", "<<max_trace[i]*5;
        cout<<endl;
        cout<<"Number of fish expected: "<<max_val<<endl<<endl;
    }
    return 0;
}
