#include<iostream>
#include<iomanip>
using namespace std;
typedef unsigned long long ull;
ull perm[21];
ull res[21];
int main(){
	perm[0]=perm[1]=1;
	for(int i=2;i<21;i++)perm[i]=perm[i-1]*i;
	res[1]=0;res[2]=1;res[3]=2;
	for(int i=4;i<21;i++)res[i]=(i-1)*(res[i-1]+res[i-2]);
	int c;cin>>c;while(c--){
		int i;cin>>i;
		cout<<fixed<<setprecision(2)<<(double(res[i])*100/perm[i])<<"%\n";
	}
	return 0;
}