#include<iostream>
#include<algorithm>
using namespace std;
double edges[3];
int main(){
    int n;
    cin>>n;
    while(n--){
        cin>>edges[0]>>edges[1]>>edges[2];
        sort(edges,edges+3);
        cout<<(edges[0]+edges[1]>edges[2]?"YES":"NO")<<endl;
    }
    return 0;
}
