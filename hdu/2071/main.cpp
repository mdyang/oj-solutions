#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		double largest=0, temp;
		int m;
		cin>>m;
		while(m--){
			cin>>temp;
			if(temp>largest)largest=temp;
		}
		cout<<std::fixed<<setprecision(2)<<largest<<endl;
	}
	return 0;
}