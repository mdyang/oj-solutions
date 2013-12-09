#include<iostream>
using namespace std;
int numbers[10001];
void init(){
	numbers[1]=2;
	for(int i=2;i<=10000;i++)
		numbers[i]=numbers[i-1]+4*(i-1)+1;
}
int main(){
	init();
	int c;
	cin>>c;
	while(c--){
		int i;cin>>i;
		cout<<numbers[i]<<endl;
	}
	return 0;
}