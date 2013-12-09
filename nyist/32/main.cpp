#include<iostream>

using namespace std;

int num[9]={1,2,3,4,5,6,7,8,9};
int stack[9];

void perm(int top, int r, int n){
    //cout<<top<<' '<<r<<' '<<n<<endl;;
    if (top==r){
        for(int i=0;i<r;i++)cout<<num[stack[i]];
        cout<<endl;
        return;
    }
    // this to be changed!
    for(int i=stack[top-1]-1;i>=r-top-1;i--){
        stack[top]=i;
        perm(top+1,r,n);
    }
}

int main(){
        int n,r;
        cin>>n>>r;
        for(int i=n-1;i>r-2;i--){
            stack[0]=i;
            perm(1,r,n);
        }

    return 0;
}
