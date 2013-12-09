#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int N,M;
	while(1){
		cin>>N>>M;
		if (!(N|M))break;
		int m = sqrt(M*2);
		for(;m>0;m--){
			if(m&1){
				if(M%m)continue;
			}
			else{
				if(M*2%m)continue;
			}
			int l=M*2/m-(m-1),r=M*2/m+(m-1);
			if (l&1)continue;
			cout<<'['<<l/2<<','<<r/2<<']'<<endl;
		}
		cout<<endl;
	}
	return 0;
}