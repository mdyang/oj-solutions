#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
class ArcadeManao{
    public:
        void try_update(int **temp,int i,int j,int val,bool& updated){
            int m=min(temp[i][j],val);
            if(m<temp[i][j]){
                temp[i][j]=m;
                updated=true;
            }
        }
        void update(vector<string>& level,int **temp,int i,int j,int h,int w,bool& updated){
            if(j>0&&level[i][j-1]=='X')try_update(temp,i,j,temp[i][j-1],updated);
            if(j<w-1&&level[i][j+1]=='X')try_update(temp,i,j,temp[i][j+1],updated);
            for(int k=i;k>=0&&i-k<temp[i][j];k--)
                if(level[k][j]=='X')try_update(temp,i,j,max(i-k,temp[k][j]),updated);
            for(int k=i;k<h-1&&k-i<temp[i][j];k++)
                if(level[k][j]=='X')try_update(temp,i,j,max(k-i,temp[k][j]),updated);
        }
        int shortestLadder(vector <string> level, int coinRow, int coinColumn){
            int height=level.size(),width=level[0].size();
            if(height==1)return 0;
            int **temp=new int*[height-1];
            for(int i=0;i<height-1;i++)temp[i]=new int[width];
            for(int i=0;i<height-1;i++)
                for(int j=0;j<width;j++)
                    if(level[i][j]=='X')temp[i][j]=height-i-1;
                    else temp[i][j]=-1;
            bool updated=false;
            do{
                updated=false;
                for(int i=0;i<height-1;i++)
                    for(int j=0;j<width;j++)
                        update(level,temp,i,j,height,width,updated);
            }while(updated);
            int ret=temp[coinRow-1][coinColumn-1];
            for(int i=0;i<height-1;i++)delete[]temp[i];
            delete[]temp;
            return ret;
        }
};



int main(){

    vector<string> e2,e3,e4;

    e2.push_back(string("..X.."));
    e2.push_back(string(".X.X."));
    e2.push_back(string("X...X"));
    e2.push_back(string(".X.X."));
    e2.push_back(string("..X.."));
    e2.push_back(string("XXXXX"));

    e3.push_back(string("X"));

    e4.push_back(string("XXXXXXXXXX"));
    e4.push_back(string("...X......"));
    e4.push_back(string("XXX......."));
    e4.push_back(string("X.....XXXX"));
    e4.push_back(string("..XXXXX..X"));
    e4.push_back(string(".........X"));
    e4.push_back(string(".........X"));
    e4.push_back(string("XXXXXXXXXX"));

    ArcadeManao am;
    cout<<am.shortestLadder(e2,1,3)<<endl;
    cout<<am.shortestLadder(e3,1,1)<<endl;
    cout<<am.shortestLadder(e4,1,1)<<endl;

    return 0;
}
