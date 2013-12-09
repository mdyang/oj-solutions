#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
int arr[100000];
int cost[100000]={0};
unsigned long long value=0;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        value+=arr[i];
    }    
    if(k>=n){
        cout<<value<<endl;
        return 0;
    }
    for(int i=0;i<=k&&i<n;i++){
        cost[i]=arr[i];
    }
    for(int i=k+1;i<n;i++){
        cost[i]=cost[i-k-1]+arr[i];
        for(int j=i-k;j<=i;j++){
            int temp=cost[j]+arr[i];
            if(temp<cost[i])cost[i]=temp;
        }
    }
    int temp=cost[n-1];
    for(int i=n-2;i>=n-k-1&&i>=0;i--)
        if(cost[i]<temp)temp=cost[i];
    cout<<value-temp<<endl;
    return 0;
}
