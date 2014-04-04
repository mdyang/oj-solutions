#include<iostream>
using namespace std;
double d[300];
int main(){
	double r = 0.5;d[0]=r;
	for(int i=1;i<300;i++){
		r+=(1.0/(i+2));
		d[i]=r;
	}
	while(1){
		double i;cin>>i;
		if (i==0.0)break;
		for(int j=0;j<300;j++)
			if (d[j]>=i){
				cout<<(j+1)<<" card(s)\n";
				break;
			}
	}
	return 0;
}