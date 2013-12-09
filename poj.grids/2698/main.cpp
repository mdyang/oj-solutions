#include<iostream>
using namespace std;
const int START=0x80;
int c=0,i=1,stack[8];
void output(){
    cout<<"No. "<<(i++)<<endl;
    for(int j=0;j<8;j++){
        for(int k=START;k>0;k>>=1)
            if(k&stack[j])cout<<"1 ";
            else cout<<"0 ";
        cout<<endl;
    }
}
void dfs(int row,int ld,int col,int rd){
    if(row==8){output();return;}
    for(int j=START;j>0;j>>=1){
        if(!(j&(ld|col|rd))){
            stack[row]=j;
            dfs(row+1,(ld|j)<<1,col|j,(rd|j)>>1);
        }
    }
}
int main(){
    for(int j=START;j>0;j>>=1){
        stack[0]=j;
        dfs(1,j<<1,j,j>>1);
    }
    return 0;
}
