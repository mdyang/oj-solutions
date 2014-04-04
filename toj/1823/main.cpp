#include<iostream>
using namespace std;
long long three[13];
void cantor(int i){
	if(i==0){
		cout<<'-';
		return;
	}
	cantor(i-1);
	for(int j=0;j<three[i-1];j++)cout<<' ';
	cantor(i-1);
}
int main(){
	three[0]=1;
	for(int i=1;i<13;i++)three[i]=three[i-1]*3;
	int c;while(cin>>c){
		cantor(c);cout<<endl;
	}
	return 0;
}