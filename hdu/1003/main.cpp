#include<iostream>
using namespace std;
short arr[100000];
int main(){
    int c;
    cin>>c;
    for(int i=1;i<=c;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        int gmax=arr[0],gstart=0,gend=0;
        for(int j=1;j<n;j++){
            if(arr[j]>gmax){
                gmax=arr[j];
                gstart=gend=j;
            }
        }
        if (gmax>=0){
        gmax=arr[0];gstart=gend=0;
        int tmax=0,tstart=0,tend=0;
        for(int j=0;j<n;j++){
            tend=j;
            tmax+=arr[j];
            if(tmax<0){
                tmax=0;
                tstart=j+1;
                continue;
            }
            if(tmax>gmax){
                gmax=tmax;
                gstart=tstart;
                gend=tend;
            }
        }
        }
        cout<<"Case "<<i<<":\n";
        cout<<gmax<<" "<<gstart+1<<" "<<gend+1<<endl;
        if(i<c)cout<<endl;
    }
    return 0;
}
