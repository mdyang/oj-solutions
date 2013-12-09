#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		int len = triangle.size();
		int** dp = new int*[len];
		for(int i=0;i<len;i++)dp[i]=new int[len];
		for(int i=0;i<len;i++)dp[len-1][i]=triangle[len-1][i];
		for(int i=len-2;i>=0;i--)
			for(int j=0;j<=i;j++){
				dp[i][j]=dp[i+1][j]<dp[i+1][j+1]?dp[i+1][j]:dp[i+1][j+1];
				dp[i][j]+=triangle[i][j];
			}
		int result=dp[0][0];
		for(int i=0;i<len;i++)delete []dp[i];
		delete []dp;
		return result;
    }
};

int main(){
	vector<vector<int> > triangle;
	triangle.push_back(vector<int>());
	triangle.push_back(vector<int>());
	triangle.push_back(vector<int>());
	
	triangle[0].push_back(-1);
	
	triangle[1].push_back(2);
	triangle[1].push_back(3);
	
	triangle[2].push_back(1);
	triangle[2].push_back(-1);
	triangle[2].push_back(-3);

	Solution solution;
	cout<<solution.minimumTotal(triangle)<<endl;
	return 0;
}