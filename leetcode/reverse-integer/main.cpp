#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sum=0;
        bool neg=x<0;
        if(neg)x=-x;
        while(x){
            sum*=10;sum+=x%10;x/=10;
        }
        if(neg)sum=-sum;
        return sum;
    }
};

int main(){
    Solution s;
    cout<<s.reverse(100)<<endl;
    cout<<s.reverse(-100)<<endl;
    cout<<s.reverse(-123)<<endl;
    cout<<s.reverse(123)<<endl;

    return 0;
}