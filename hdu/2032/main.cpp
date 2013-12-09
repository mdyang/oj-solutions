#include<iostream>
using namespace std;
int triangle[30][30];
int main(){
    triangle[0][0]=1;
    for(int i=1;i<30;i++){
        triangle[i][0]=triangle[i][i]=1;
        for(int j=1;j<i;j++){
            triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
        }
    }
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cout<<triangle[i][0];
            for(int j=1;j<=i;j++)cout<<' '<<triangle[i][j];
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
