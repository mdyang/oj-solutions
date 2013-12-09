#include<iostream>
using namespace std;
int main(){
	int c;cin>>c;
	while(c--){
		__int64 a,b;cin>>a>>b;
		cout<<(a%b?"NO":"YES")<<endl;
	}
	return 0;
}