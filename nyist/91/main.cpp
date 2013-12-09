#include <iostream>
#include <set>

using namespace std;

const int NUM =9;
int nums[NUM] = {1,2,6,24,120,720,5040,40320,362880};

int main(){

    set<int> s;
    for (int i=0;i<1<<NUM;i++){
        int sum=0;
        for(int j=0;j<NUM;j++){
            if(i&1<<j)sum+=nums[j];
        }
        s.insert(sum);
    }

    int c;
    cin>>c;
    while(c--){
        int t;
        cin>>t;
        if(s.find(t)==s.end())cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }

    return 0;
}
