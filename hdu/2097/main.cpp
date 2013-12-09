#include<iostream>
using namespace std;
int digisum(int n,int base){
	int sum=0;
	while(n){
		sum+=(n%base);
		n/=base;
	}
	return sum;
}
int main(){
	int i;
	while(1){
		cin>>i;
		if(!i)break;
		int s=digisum(i,10);
		int s2=digisum(i,16);
		int s3=digisum(i,12);
		bool failed=false;
		if(!(s==s2 && s==s3)) failed=true;
		cout<<i<<" is "<<(failed?"not ":"")<<"a Sky Number.\n";
	}
	return 0;
}