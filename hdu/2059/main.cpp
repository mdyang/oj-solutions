#include<iostream>
#include<climits>
using namespace std;
double fastest[102];
int L,N,C,T,VR,VT1,VT2,P[102];
int main(){
	while(1){
		if (!(cin>>L))break;
		cin>>N>>C>>T>>VR>>VT1>>VT2;
		P[0]=fastest[0]=0;
		for(int i=1;i<=N;i++){
			cin>>P[i];
			fastest[i]=INT_MAX;
		}
		fastest[N+1]=INT_MAX;
		P[N+1]=L;
		double rtime=double(L)/VR,ttime=0;
		for(int j=1;j<=N+1;j++)
			for(int i=0;i<j;i++){
				int dist=P[j]-P[i];
				int c_dist=dist>C?C:dist;
				int vt2_dist=dist-c_dist;
				double time=(double)c_dist/VT1+(double)vt2_dist/VT2;
				if(i)time+=T;
				time+=fastest[i];
				if(time<fastest[j])fastest[j]=time;
			}
		ttime=fastest[N+1];		
		if(rtime<ttime) cout<<"Good job,rabbit!\n";
		else cout<<"What a pity rabbit!\n";
	}
	return 0;
}
