#include<iostream>
#include<cmath>
using namespace std;
int mysqrt(int n){
	if(n<0)return -1;
	int rt=sqrt(double(n));
	if (rt*rt==n)return rt;
	return -1;
}
int main(){
	int a,b;
	while(1){
		cin>>a>>b;
		if((a|b)==0)break;
		int rt=mysqrt(a*a-4*b);
		bool fail=false;
		if(rt==-1)fail=true;
		else{
			if((a+rt)%2!=0 || (a-rt)%2!=0)fail=true;
		}
		if(fail)cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}