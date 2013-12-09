#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull _c[21][21],result[21][21];
ull c(int m,int n){
	if(m-n<n)return c(m,m-n);
	return _c[m][n];
}
ull sqr(ull i){ return i*i; }
int main(){
	int i,j;
	for(i=1;i<21;i++){
		_c[i][1]=i;_c[i][0]=1;
		for(j=2;j<=i/2;j++)_c[i][j]=_c[i][j-1]*(i+1-j)/j;
	}
	result[2][2]=1;result[3][2]=3;result[3][3]=2;
	for(i=4;i<21;i++){
		result[i][i]=(result[i-1][i-1]+result[i-2][i-2])*(i-1);
		for(j=2;j<i;j++)result[i][j]=result[j][j]*c(i,j);
	}	
	int c;cin>>c;while(c--){
		int m,n;cin>>m>>n;
		cout<<result[m][n]<<endl;
	}
	return 0;
}