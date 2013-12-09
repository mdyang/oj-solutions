#include<iostream>
#include<string>
using namespace std;
int main(){
	while(1){
		string a,b;
		cin>>a;
		if(!a.compare("#"))break;
		cin>>b;
		int count=0;
		size_t pos=0;
		while(1){
			if((pos=a.find(b,pos))!=string::npos){
				count++;
				pos+=b.size();
			}
			else break;
		}
		cout<<count<<endl;
	}
	return 0;
}