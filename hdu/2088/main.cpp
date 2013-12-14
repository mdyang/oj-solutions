#include<iostream>
using namespace std;
int b[64];
int main(){
	int c;bool first=true;
	while(1){
		cin>>c;
		if(!c)break;
		if(first)first=false;
		else cout<<endl;
		int sum=0;
		for(int i=0;i<c;i++){cin>>b[i];sum+=b[i];}
		int mean=sum/c;sum=0;
		for(int i=0;i<c;i++)if(b[i]>mean)sum+=(b[i]-mean);
		cout<<sum<<endl;
	}
	return 0;
}