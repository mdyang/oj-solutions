#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main(){
	string a;
	double b,c,sum=0;
	while(cin>>a>>b>>c){
		sum+=b*c;
	}
	cout<<fixed<<setprecision(1)<<sum<<endl;
	return 0;
}