#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int dp[1000][1000];
// lcs of string [l..0](reverse of [0..l]) and [r..n-1]
int calc(string& s, int l, int r){
    int n=s.size();
    if(l==-1||r==n)if(l+2==r)return n-1;else return n;
    if(s.at(l)==s.at(r))dp[0][0]=1;else dp[0][0]=0;
    int i=1,j=1;
    for(i=1;i<=l;i++){
        if(s.at(l-i)==s.at(r))dp[i][0]=1;
        else dp[i][0]=dp[i-1][0];
    }
    for(i=1;r+i<n;i++){
        if(s.at(l)==s.at(r+i))dp[0][i]=1;
        else dp[0][i]=dp[0][i-1];
    }
    for(i=1;i<=l;i++)
        for(j=1;r+j<n;j++){
            if(s.at(l-i)==s.at(r+j))dp[i][j]=max(dp[i-1][j-1]+1,max(dp[i-1][j],dp[i][j-1]));
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    int result=dp[i-1][j-1];
    result=n-result*2;
    if(l+2==r)result--;
    return result;
}
int min_possible(int l,int r,int n){
    return abs(n-r-l-1);
}
int main(){
    int c;
    cin>>c;
    while(c--){
        string s;
        cin>>s;
        if(s.size()==1||(s.size()==2&&s.at(0)==s.at(1))){
            cout<<0<<endl;
            continue;
        }
        int m=s.size();
        int pivot=m/2;
        int temp;
        temp=calc(s,pivot-1,pivot+1);
        if(temp<m)m=temp;
        temp=calc(s,pivot-1,pivot);
        if(temp<m)m=temp;

        for(int i=pivot-1;i>=-1,min_possible(i,i+1,s.size())<m;i--){
            temp=calc(s,i,i+1);
            if(temp<m)m=temp;
        }
        for(int i=pivot+1;i<s.size(),min_possible(i,i+1,s.size())<m;i++){
            temp=calc(s,i,i+1);
            if(temp<m)m=temp;
        }
        for(int i=pivot-1;i>=0,min_possible(i-1,i+1,s.size())<m;i--){
            temp=calc(s,i-1,i+1);
            if(temp<m)m=temp;
        }
        for(int i=pivot+1;i<s.size(),min_possible(i-1,i+1,s.size())<m;i++){
            temp=calc(s,i-1,i+1);
            if(temp<m)m=temp;
        }
        cout<<m<<endl;
    }
    return 0;
}
