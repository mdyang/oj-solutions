#include<iostream>
#include<memory.h>
unsigned long long m[35][35];
using namespace std;
int main(){
	int n,a=1;
	while(1){
		cin>>n;
		if(n==-1)break;
		memset(m,0,sizeof(m));
		for(int i=0;i<=n;i++)
			m[i][0]=1;
		for(int i=1;i<=n;i++){
			m[n-i][i]=m[n-i][i-1];
			for(int j=n-i-1;j>=0;j--){
				m[j][i]=m[j+1][i]+m[j][i-1];
			}
		}
		cout<<(a++)<<' '<<n<<' '<<(m[0][n]*2)<<endl;
	}
	return 0;
}