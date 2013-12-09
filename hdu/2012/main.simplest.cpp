#include<iostream>
using namespace std;
int main(){
	int x,y;
	while(1){
			cin>>x>>y;
			if((x|y)==0)break;
			if(x>=-39&&y<=39||x>=42&&y<=43||x>=45&&y<=48)cout<<"OK\n";
			else cout<<"Sorry\n";
	}
	return 0;
}