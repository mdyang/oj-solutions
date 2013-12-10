#include<iostream>
#include<memory.h>
using namespace std;
bool bit[20];
int p[20]={1};
int main(){
	int n,m;
	for(int i=1;i<20;i++)p[i]=p[i-1]*2;
	while(cin>>n>>m){
		memset(bit,20,sizeof(bool));
		for(int i=n;p;i--){
			int d=m/p[i];
			m%=p[i];
			if(d){
				for(int j=0;;){
					if(j
				}
			}
		}
	}
	return 0;
}