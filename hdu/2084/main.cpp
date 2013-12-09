#include<iostream>
#include<cmath>
using namespace std;
int t[100][100],dp[100][100];
int main(){
	int c;cin>>c;while(c--){
		int n;cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)cin>>t[i][j];
		if(n==1)dp[0][0]=t[0][0];
		else{
			for(int i=0;i<n;i++)dp[n-1][i]=t[n-1][i];
			for(int i=n-2;i>=0;i--){
				for(int j=0;j<=i;j++){
					dp[i][j]=max(dp[i+1][j]+t[i][j],dp[i+1][j+1]+t[i][j]);
				}
			}
		}
		cout<<dp[0][0]<<endl;
	}
}