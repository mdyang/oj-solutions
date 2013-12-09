#include<iostream>
using namespace std;
unsigned long long l[51];
void init(){
	l[1]=3;l[2]=l[3]=6;
	for(int i=4;i<51;i++){
		l[i]=l[i-1]+2*l[i-2];
	}
}
int main(){
	init();
	int c;while(cin>>c){
		
		cout<<l[c]<<endl;
	}
	return 0;
}