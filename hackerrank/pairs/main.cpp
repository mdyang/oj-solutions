#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int arr[100000];
int main(){
    int n,k;
    cin>>n>>k;
    set<int> s;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr[i]=temp;
        s.insert(temp);
    }
    sort(arr,arr+n);
    int count=0;
    for(int i=0;i<n;i++)if(s.find(arr[i]+k)!=s.end())count++;
    cout<<count<<endl;
    return 0;
}
