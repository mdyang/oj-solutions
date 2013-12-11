#include<iostream>
#include<memory.h>
using namespace std;
bool matrix[512][512],d[512];
int n[512];
int K,M,N;
bool find(int a){
	for(int i=1;i<=N;i++){
		if(!d[i]&&matrix[a][i]){
			d[i]=true;
			if(!n[i]||find(n[i])){
				n[i]=a;
				return true;
			}
		}
	}
	return false;
}
int main(){
	while(1){
		cin>>K;
		if(!K)break;
		cin>>M>>N;
		memset(matrix,0,sizeof(matrix));
		memset(n,0,sizeof(n));
		int i=K,j,k;
		while(i--){
			cin>>j>>k;
			matrix[j][k]=true;
		}
		int c=0;
		for(int i=1;i<=M;i++){
			memset(d,0,sizeof(d));
			if(find(i))c++;
		}
		cout<<c<<endl;
	}
	return 0;
}