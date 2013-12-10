#include<iostream>
using namespace std;
int sum[6] = {7,13,18,22,25,27};
int main(){
	int n;
	cin>>n;
	while(n--){
		int b,p,o;
		cin>>b>>p>>o;
		if(b>6){
			p+=(8*(b-6));
			b=6;
		}
		p+=sum[b-1];
		cout<<(p>=o?"Yes":"No")<<endl;
	}
	return 0;
}