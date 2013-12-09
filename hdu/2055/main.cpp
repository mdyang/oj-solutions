#include<iostream>
#include<string>
using namespace std;
int upper[26];
int lower[26];
int get_val(char c){
	if(c >= 'a' && c <= 'z')return lower[c-'a'];
	return upper[c-'A'];
}
void init(){
	for(int i=0;i<26;i++){
		int v=i+1;
		lower[i]=-v;
		upper[i]=v;
	}
}
int main(){
	init();
	int i;
	cin>>i;
	while(i--){
		char c;int n;
		cin>>c>>n;
		cout<<get_val(c)+n<<endl;
	}
	return 0;
}