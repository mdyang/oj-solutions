#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

int dp[21][21];

int lcs(vector<int> &a, vector<int> &b){
  
    if (a[0]==b[0]) dp[0][0]=1;
    else dp[0][0]=0;

    for (int i=1;i<a.size();i++){
        if (dp[i-1][0]) dp[i][0]=1;
        else{
            if (a[i]==b[0]) dp[i][0]=1;
            else dp[i][0]=0;
        }
        if (dp[0][i-1]) dp[0][i]=1;
        else{
            if (b[i]==a[0]) dp[0][i]=1;
            else dp[0][i]=0;
        }
    }

    for (int i=1;i<a.size();i++){
        for (int j=1;j<a.size();j++){
            // if (a[i]=b[j]) dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]), dp[i-1][j-1]+1);
            if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[a.size()-1][a.size()-1];
}

int main(){

    int N;
    cin >> N;
    while(N--){
        vector<int> nums;
        vector<int> dups;
        int m;
        cin>>m;
        for (int i=0;i<m;i++){
            int temp;
            cin>>temp;
            nums.push_back(temp);
            dups.push_back(temp);
        }

        sort(dups.begin(), dups.end());

        for (int i=0;i<m/2;i++){
            swap(dups[i], dups[m-i-1]);
        }

        cout<<lcs(nums, dups)<<endl;

    }

    return 0;
}
