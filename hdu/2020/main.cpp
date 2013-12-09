#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int number[100];
int index[100];
int comp(int i,int j){
    return abs(number[i])>abs(number[j]);
}
int main(){
    int n;
    while((cin>>n)&&n>0){
        for(int i=0;i<n;i++)index[i]=i;
        for(int i=0;i<n;i++)cin>>number[i];
        sort(index,index+n,comp);
        cout<<number[index[0]];
        for(int i=1;i<n;i++)cout<<' '<<number[index[i]];
        cout<<endl;
    }
    return 0;
}
