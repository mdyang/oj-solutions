#include <iostream>
#include <memory.h>

int nums[21];
int dp[21];

using namespace std;

int main(){

    int N;
    cin >> N;
    while(N--){
 
       int m;
        cin>>m;
        for (int i=0;i<m;i++){
            cin>>nums[i];
        }

        int longest = 0;
        for (int i=0;i<m;i++){
            dp[i]=1;
            for (int j=0;j<i;j++){
                if (nums[i]<nums[j]){
                    if (dp[j]+1>dp[i]){ 
                        dp[i]=dp[j]+1;
                    }
                }
            }
            if (longest<dp[i])longest=dp[i];
        }

        cout<<longest<<endl;

    }

    return 0;
}
