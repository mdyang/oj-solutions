#include<iostream>
#include<memory.h>
#include<set>
#include<algorithm>
#include<deque>
using namespace std;
typedef unsigned long long ull;
ull n[600001],p[60000],pc=0;
ull get(ull a){
	if(a==1||a==0)return 0;
	if(!n[a])return 1;
	set<ull> s;s.insert(1);
	deque<ull> dq;
	dq.push_back(n[a]);
	int t=a;
	while(dq.size()>0){
		ull temp=dq.front();
		ull divide=a/temp;
		dq.pop_front();
		set<ull> s1;
		for(set<ull>::iterator i=s.begin();i!=s.end();i++){
			ull prod=(*i)*temp;
			if(prod<t && t%prod==0)s1.insert(prod);
			prod=(*i)*divide;
			if(prod<t && t%prod==0)s1.insert(prod);
		}
		for(set<ull>::iterator i=s1.begin();i!=s1.end();i++)s.insert(*i);
		
		if(n[divide]!=0)dq.push_back(n[divide]);
		a=divide;
	}
	ull sum=0;
	for(set<ull>::iterator i=s.begin();i!=s.end();i++)
		sum+=(*i);
	return sum;
}
void init(){
	n[0]=n[1]=1;
	for(ull i=2;i<600001;i++){
		if(!n[i])p[pc++]=i;
		for(ull j=0;j<pc&&p[j]*i<600001;j++){
			n[p[j]*i]=p[j];
			if(i%p[j]==0)break;
		}
	}
}
int main(){
	init();
	ull c;cin>>c;while(c--){
		ull a,b;cin>>a>>b;
		bool failed=false;
		if(!(a==get(b)&&b==get(a)))failed=true;
		if(failed)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}