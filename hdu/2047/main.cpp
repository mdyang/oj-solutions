#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull n[40],o[40];
int main(){
	n[1]=2;o[1]=1;
	for(int i=2;i<40;i++){
		n[i]=(n[i-1]+o[i-1])*2;
		o[i]=n[i-1];
	}
	int c;while(cin>>c)cout<<(o[c]+n[c])<<endl;
	return 0;
}