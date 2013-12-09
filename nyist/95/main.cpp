#include<iostream>
#include<hash_map>

using namespace std;
using namespace __gnu_cxx;

int main(){
    int c;
    cin>>c;
    while(c--){
        hash_map<int,int> h;
        int n;
        cin>>n;
        int temp, sum=0, num;
        while(n--){
            cin>>temp;
            int count = h[temp];
            h[temp]=++count;
            if(count>sum){
                sum=count;
                num=temp;
            }
        }
        cout<<num<<' '<<sum<<endl;
    }
    
    return 0;
}
