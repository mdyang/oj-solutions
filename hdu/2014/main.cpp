#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int score[100];
int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>score[i];
        }
        sort(score,score+n);
        double sum=0;
        for(int i=1;i<n-1;i++){
            sum+=score[i];}
        sum/=(n-2);
        cout<<fixed<<setprecision(2)<<sum<<endl;
    }
    return 0;
}
