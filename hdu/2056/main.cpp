#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
double x[4], y[4];
double intersection_area(){
	if (x[2]>=x[1]||x[3]<=x[0]||y[2]>=y[1]||y[3]<=y[0]) return 0;
	sort(x,x+4);
	sort(y,y+4);
	return (x[2]-x[1])*(y[2]-y[1]);
}
int main(){
	while(1){
		for(int i=0;i<4;i++)
			if(!(cin>>x[i]>>y[i]))
				return 0;
		sort(x,x+2);
		sort(y,y+2);
		sort(x+2,x+4);
		sort(y+2,y+4);
		cout<<fixed<<setprecision(2)<<intersection_area()<<endl;
	}
	return 0;
}