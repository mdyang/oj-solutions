#include<iostream>
#include<algorithm>
using namespace std;
int x[41];
inline int sqr(int i){return i*i;}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		int i;
		for(i=0;i<n;i++)cin>>x[i];
		sort(x,x+n);
		cout<<sqr(100-x[0])<<endl;
	}
	return 0;
}