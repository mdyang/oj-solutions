#include<stdio.h>
#include<queue>
using namespace std;
int curval,maxval;
int f[25],d[25],t[25];
int n,h;
struct fish{
    int f;
    int i;
    bool operator<(const fish& a)const{
        return f<a.f||(f==a.f&&i>a.i);
    }
};
int main(){
    t[0]=0;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        scanf("%d",&h);
        h*=12;
        for(int i=0;i<n;i++)scanf("%d",&f[i]);
        for(int i=0;i<n;i++)scanf("%d",&d[i]);
        for(int i=1;i<n;i++)scanf("%d",&t[i]);
        int max_val=0;
        int max_trace[25];
        // lake i as the last lake
        for(int i=0;i<n;i++){
            priority_queue<fish> q;
            int temp_trace[25]={0};
            for(int j=0;j<=i;j++){
                fish _f;
                _f.f=f[j];
                _f.i=j;
                q.push(_f);
            }
            int _t=h;
            // subtract the time on the road from total time
            for(int j=0;j<=i;j++)_t-=t[j];
            if(_t<=0)break;
            int temp_val=0;
            // fish!
            while(_t){
                fish _f=q.top();
                // no more fish
                if(!_f.f){
                    temp_trace[0]+=_t;
                    break;
                }
                q.pop();
                temp_val+=_f.f;
                temp_trace[_f.i]++;
                // decrease fish in lake _i
                _f.f-=d[_f.i];
                if(_f.f<0)_f.f=0;
                q.push(_f);
                _t--;
            }
            if(temp_val>max_val){
                max_val=temp_val;
                for(int i=0;i<n;i++)max_trace[i]=temp_trace[i];
            }
        }
        printf("%d",max_trace[0]*5);
        for(int i=1;i<n;i++)printf(", %d",max_trace[i]*5);
        printf("\n");
        printf("Number of fish expected: %d\n\n",max_val);
    }
    return 0;
}
