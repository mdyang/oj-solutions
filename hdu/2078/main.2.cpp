#include<iostream>
#include<algorithm>
using namespace std;
int x[41];
inline int sqr(int i){return i*i;}
int calc(int n,int m){
	int i,maxdiff=0,delta=n+1-m;
	for(i=0;i<=n-delta;i++)if(maxdiff<x[i+delta]-x[i])maxdiff=x[i+delta]-x[i];
	int fmax=0;
	for(i=0;i<=n-delta;i++){
		if(maxdiff==x[i+delta]-x[i]){
			int j,tmax=0;
			for(j=0;j<i;j++)tmax+=sqr(x[j+1]-x[j]);
			tmax+=sqr(x[j+delta]-x[j]);
			for(j+=delta;j<n;j++)tmax+=sqr(x[j+1]-x[j]);
			if(fmax<tmax)fmax=tmax;
		}
	}
	return fmax;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		int i;
		for(i=0;i<n;i++)cin>>x[i];
		x[i]=100;
		sort(x,x+n+1);
		int fmax=0;
		while(m){
			int tmax=calc(n,m--);
			if(tmax>fmax)fmax=tmax;
		}
		cout<<fmax<<endl;
	}
	return 0;
}