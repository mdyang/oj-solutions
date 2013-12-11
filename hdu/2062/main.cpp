#include<iostream>
#include<memory.h>
using namespace std;
bool bit[20];
unsigned long long p[21];
int get(int i){
	int j=-1,k=0;
	for(;;k++){
		if(!bit[k])j++;
		if(j==i){
			bit[k]=true;
			return k+1;
		}
	}
}
int main(){
	unsigned long long n,m;
	p[1]=1;
	for(int i=2;i<=20;i++)p[i]=(p[i-1]+1)*i;
	while(cin>>n>>m){
		memset(bit,0,21*sizeof(bool));
		bool first=true;
		for(int i=n-1;m;i--){
			int d=(m-1)/(p[i]+1);
			m=(m-1)%(p[i]+1);
			if(first)first=false;
			else cout<<' ';
			cout<<(get(d));			
		}
		cout<<endl;
	}
	return 0;
}