#include<vector>
#include<map>
#include<iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		map<int,int> m;
		for(vector<int>::iterator i=num.begin();i!=num.end();i++){
			if(!m[*i])m[*i]=m[*i-1]+1;
			for(int j=*i+1;m[j];j++)m[j]=m[j-1]+1;
		}
		int max=0;
		for(map<int,int>::iterator i=m.begin();i!=m.end();i++){
			if(i->second > max)max = i->second;
		}
		return max;
    }
};

int main(){

	vector<int> num;
	num.push_back(100);
	num.push_back(4);
	num.push_back(200);
	num.push_back(1);
	num.push_back(3);
	num.push_back(2);

	Solution sol;
	cout<<(sol.longestConsecutive(num))<<endl;
	return 0;
}