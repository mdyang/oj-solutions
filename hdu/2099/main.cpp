#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int m,n;
	while(1){
		cin>>m>>n;
		if(!(m|n))break;
		m*=100;
		int i=m%n;
		int first=true;
		for(int j=-i;j<100;j+=n){
			if(j>=0){
				if(first)first=false;
				else cout<<' ';
				cout<<setw(2)<<setfill('0')<<j;
			}
		}
		cout<<endl;
	}
	return 0;
}