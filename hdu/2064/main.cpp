#include<iostream>
using namespace std;
unsigned long long r[36];
void init(){
	r[1]=2;
	for(int i=2;i<=35;i++)r[i]=r[i-1]*3+2;
}
int main(){
	init();
	int c;while(cin>>c)cout<<r[c]<<endl;
	return 0;
}