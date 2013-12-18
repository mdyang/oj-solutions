#include<iostream>
using namespace std;
inline int sqr(int i){return i*i;}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		int i;int min=100,t;
		for(i=0;i<n;i++){
			cin>>t;
			if(t<min)min=t;
		}
		cout<<sqr(100-min)<<endl;
	}
	return 0;
}