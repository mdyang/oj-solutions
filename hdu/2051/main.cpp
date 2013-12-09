#include<iostream>
using namespace std;
bool result[10];
int length;
int main(){
	int i;
	while(cin>>i){
		length=0;
		while(i){
			result[length++]=i&1;
			i>>=1;
		}
		
		for(int j=length-1;j>=0;j--)
			if(result[j])cout<<1;
			else cout<<0;
		cout<<endl;
	}
	return 0;
}