#include<iostream>
#include<algorithm>
using namespace std;
int arr[4];
int main(){
    int i=1;
    while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]){
        sort(arr,arr+4);
        cout<<"Case "<<(i++)<<": "<<arr[3]+arr[2]<<endl;
    }
    return 0;
}
