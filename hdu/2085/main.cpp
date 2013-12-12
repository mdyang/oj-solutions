#include<iostream>
using namespace std;
unsigned long long a[34][2];
int main(){
	a[0][0]=1;a[0][1]=0;
	for(int i=1;i<34;i++){
		a[i][0]=3*a[i-1][0]+2*a[i-1][1];
		a[i][1]=a[i-1][0]+a[i-1][1];
	}
	int n;
	while(1){
		cin>>n;
		if(n==-1)break;
		cout<<a[n][0]<<", "<<a[n][1]<<endl;
	}
	return 0;
}