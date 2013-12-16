#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double fix[200];
double rt2=sqrt(2);
struct p{int x[2];};
int main(){
	for(int i=0;i<200;i++)
		fix[i]=sqrt(i*i+(i+1)*(i+1));
	int n;cin>>n;
	while(n--){
		struct p p1,p2,t;
		cin>>p1.x[0]>>p1.x[1]>>p2.x[0]>>p2.x[1];
		int start=p1.x[0]+p1.x[1],end=p2.x[0]+p2.x[1];
		if(start==end){
			cout<<fixed<<setprecision(3)<<(rt2*fabs(double(p1.x[0]-p2.x[0])))<<endl;
		}
		else{
			if(start>end){
				int temp;
				temp=start;
				start=end;
				end=temp;
				t=p1;p1=p2;p2=t;
			}
			double dist=0;
			for(int i=start;i<end;i++)dist+=fix[i];
			for(int i=start+1;i<end;i++)dist+=(i*rt2);
			if(start<end)
				dist+=(p1.x[1]*rt2+p2.x[0]*rt2);
			cout<<fixed<<setprecision(3)<<dist<<endl;
		}
	}
	return 0;
}