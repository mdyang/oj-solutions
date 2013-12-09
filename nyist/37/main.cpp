#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int dp[1000][1000];
int lcs(string& s){
    if(s.at(0)==s.at(s.size()-1))dp[0][0]=1;else dp[0][0]=0;
    for(int i=1;i<s.size();i++){
        if(s.at(i)==s.at(s.size()-1))dp[i][0]=1;
        else dp[i][0]=dp[i-1][0];
    }
    for(int i=1;i<s.size();i++){
        if(s.at(s.size()-1-i)==s.at(0))dp[0][i]=1;
        else dp[0][i]=dp[0][i-1];
    }
    for(int i=1;i<s.size();i++)
        for(int j=1;j<s.size();j++){
            if(s.at(i)==s.at(s.size()-1-j))dp[i][j]=max(dp[i-1][j-1]+1,max(dp[i-1][j],dp[i][j-1]));
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    return dp[s.size()-1][s.size()-1];
}
int main(){
    int c;
    cin>>c;
    while(c--){
        string s;
        cin>>s;
        cout<<s.size()-lcs(s)<<endl;
    }
    return 0;
}
