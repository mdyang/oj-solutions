#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
ll parse(string&s){
	ll sign=1;if(s[0]=='-')sign=-1;
	ll sum=0;
	int i;
	for(i=((s[0]=='-'||s[0]=='+')?1:0);i<s.size();i++){
		sum<<=4;sum+=(s[i]<'A'?(s[i]-'0'):(s[i]-55));
	}
	return sum*sign;
}
int main(){
	string a,b;
	while(cin>>a>>b){
		ll res=parse(a)+parse(b);
		if(res<0){cout<<'-';res=-res;}
		cout<<hex<<uppercase<<res<<endl;
	}
	return 0;
}