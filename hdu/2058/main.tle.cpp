#include<iostream>
using namespace std;
int main(){
	int N,M;bool first=true;
	while(1){
		cin>>N>>M;
		if (!(N|M))break;
		if (first){
			first=false;
		}
		else{
			cout<<endl;
		}
		int i=1,j=1,sum=1;
		for(;j<=N&&j<=M;sum+=(++j)){
			if(sum==M)cout<<'['<<i<<','<<j<<']'<<endl;
			else if(sum>M){
				while((i<=j)&&sum>M){
					sum-=i;
					i++;
				}
				if(sum==M)cout<<'['<<i<<','<<j<<']'<<endl;
			}
		}
	}
	return 0;
}