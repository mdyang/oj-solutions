#include<iostream>
using namespace std;
unsigned long long l[51],i[51];
void init(){
	i[1]=i[2]=0;l[1]=3;l[2]=6;
	for(int j=3;j<51;j++){
		l[j]=l[j-1]+2*i[j-1];
		i[j]=l[j-1];
	}
}
int main(){
	init();
	int c;while(cin>>c){
		
		cout<<l[c]<<endl;
	}
	return 0;
}