#include<iostream>
#include<cmath>
#include<memory.h>
int n[90];bool b[90];
using namespace std;
int numbers[3000],primes[3000],pcount=0;
int gen(int i){ return i*i+i+41; }
bool isprime(int i){ return numbers[i]==0; }
void genprime(){
	memset(numbers,0,sizeof(numbers));
	numbers[0]=numbers[1]=1;
	for(int i=2;i<3000;i++){
		if(!numbers[i])primes[pcount++]=i;
		for(int j=0;j<pcount&&primes[j]*i<3000;j++){
			numbers[i*primes[j]]=primes[j];
			if(i%primes[j]==0)break;
		}
	}
}
void init(){
	genprime();
	for(int i=0;i<90;i++)n[i]=gen(i-39);
	for(int i=0;i<90;i++)b[i]=isprime(n[i]);
}
int main(){
	init();
	int x,y;
	while(1){
			cin>>x>>y;
			if((x|y)==0)break;
			bool failed=false;
			for(int i=x;i<=y;i++)if(!b[i+39]){
				failed=true;break;
			}
			if(failed)cout<<"Sorry\n";
			else cout<<"OK\n";
	}
	return 0;
}