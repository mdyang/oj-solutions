#include<iostream>
#include<memory.h>
using namespace std;
int n[10001],p[10000],pc=0;
void init(){
	memset(n,0,sizeof(n));
	n[0]=n[1]=0;
	for(int i=2;i<10001;i++){
		if(!n[i])p[pc++]=i;
		for(int j=0;j<pc&&p[j]*i<10001;j++){
			n[p[j]*i]=p[j];
			if(i%p[j]==0)break;
		}
	}
}
int main(){
	init();
	int x;
	while(1){
		cin>>x;if(!x)break;
		int c=0,h=x/2;
		for(int i=0;i<pc&&p[i]<h;i++)
			if(!n[x-p[i]])
				++c;
		cout<<c<<endl;
	}
	return 0;
}