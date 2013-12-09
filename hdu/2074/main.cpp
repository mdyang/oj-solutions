#include<iostream>
using namespace std;
void print_header(int c,char ch){
	cout<<' ';
	for(int i=0;i<c-2;i++)cout<<ch;
	cout<<" \n";
}
int main(){
	int c;char ch[2];bool first=true;
	while(cin>>c>>ch[0]>>ch[1]){
		if(first){first=false;}
		else{cout<<endl;}
		if(c==1)cout<<ch[0]<<endl;
		else{
			int init=(c/2)%2;
			print_header(c,ch[init]);
			int i,j,k;
			for(j=1,i=init;j<c/2;j++,i=init){
				for(k=0;k<j;k++,i=(i+1)%2)
					cout<<ch[i];
				for(k=0;k<c-(j*2);k++)
					cout<<ch[i];
				for(k=0,i=(i+1)%2;k<j;k++,i=(i+1)%2)
					cout<<ch[i];
				cout<<endl;
			}
			for(j=c/2,i=init;j>=1;j--,i=init){
				for(k=0;k<j;k++,i=(i+1)%2)
					cout<<ch[i];
				for(k=0;k<c-(j*2);k++)
					cout<<ch[i];
				for(k=0,i=(i+1)%2;k<j;k++,i=(i+1)%2)
					cout<<ch[i];
				cout<<endl;
			}
			print_header(c,ch[init]);
		}
	}
	return 0;
}