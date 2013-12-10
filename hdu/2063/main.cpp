#include<iostream>
#include<memory.h>
using namespace std;
bool N[500],M[500];
int main(){
	int k,m,n;
	while(1){
		cin>>k;
		if(!k)break;
		memset(N,500,sizeof(bool));
		memset(M,500,sizeof(bool));
		cin>>m>>n;
		while(k--){
			int a,b;
			cin>>a>>b;
			M[a-1]=true;
			N[b-1]=true;
		}
		int c=0,d=0;
		for(int i=0;i<m;i++)if(M[i])c++;
		for(int i=0;i<n;i++)if(N[i])d++;
		cout<<(c<d?c:d)<<endl;
	}
	return 0;
}