#include<iostream>
#include<cmath>
#include<memory.h>
using namespace std;
int n[90];bool b[90];
int numbers[3000],primes[3000],pcount=0;
int gen(int i){ return i*i+i+41; }
//int test[10]={2,3,5,7,9,11,13,17,19,23};
int test[10]={2,3,4,5,6,7,8,9,10,11};
// calculate a*b mod n
int mulmod(int a,int b, int n){ return ((a%n)*(b%n))%n; }
// calculate a^b mod n
int expmod(int a,int b,int n){
	if(b==0)return 1;if(b==1)return a%n;
	int m;
	if(b&1){
		return mulmod(a,expmod(a,b-1,n),n);
	}
	m=expmod(a,b/2,n);
	return mulmod(m,m,n);
}
// test primality of i with base b
bool R_M(int i,int b){
	int k=0,m=i-1;
	while(!(m&1)){m>>=1;k++;}
	int mod=expmod(b,m,i);
	if(mod==1 || mod==i-1)return true;
	for(int j=1;j<k;j++){
		mod=mulmod(mod,mod,i);
		if(mod==i-1)return true;
	}
	return false;
}
bool isprime(int i){
	if(i==0||i==1)return false;
	if(i==2)return true;
	for(int j=1;j<10;j++)
		if(!R_M(i,test[j]))return false;
	return true;
}
void init(){
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