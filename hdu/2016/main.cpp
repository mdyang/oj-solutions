#include<iostream>
#include<climits>
using namespace std;
int arr[100];
void swap(int i,int j){
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;
}
int main(){
    int n;
    while(cin>>n&&n>0){
        int index=0,max=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]<max){
                max=arr[i];index=i;
            }
        }
        swap(0,index);
        cout<<arr[0];
        for(int i=1;i<n;i++)cout<<" "<<arr[i];
        cout<<endl;
    }
    return 0;
}
