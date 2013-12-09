#include<iostream>
using namespace std;
__int64 sol[51];
void init(){
	sol[1]=1;
	sol[2]=2;
	for(int i=3;i<=50;i++)sol[i]=sol[i-1]+sol[i-2];
}
int main(){
	init();
	int c;
	while(cin>>c){
		cout<<sol[c]<<endl;
	}
	return 0;
}