#include <iostream>

using namespace std;

unsigned int row;
unsigned int col;

short map[101][101];

short dp[2][101][101];

int main(){

    int c;
    cin>>c;
    while(c--){
        cin>>row>>col;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                cin>>map[i][j];
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                dp[0][i][j]=1;

        int i;
        bool changed=true;
        for(i=1;changed&&i<row*col;i++){
            changed=false;
            //cout<<"i="<<i<<endl;
            int cur=i%2;
            int last=(i-1)%2;
            for(int j=0;j<row;j++)
                for(int k=0;k<col;k++){
                    dp[cur][j][k]=dp[last][j][k];
                    // left neighbor
                    if (k>0){
                        if(map[j][k-1]>map[j][k]&&dp[last][j][k-1]+1>dp[cur][j][k]){
                            changed=true;
                            dp[cur][j][k]=dp[last][j][k-1]+1;
                        }
                    }
                    // right neighbor
                    if (k<col-1){
                        //cout<<"dp[i-1][j][k]="<<dp[i-1][j][k]<<" dp[i][j][k]="<<dp[i][j][k]<<endl;
                        if(map[j][k+1]>map[j][k]&&dp[last][j][k+1]+1>dp[cur][j][k]){
                            changed=true;
                            dp[cur][j][k]=dp[last][j][k+1]+1;
                        }
                    }
                    // up neighbor
                    if (j>0){
                        if(map[j-1][k]>map[j][k]&&dp[last][j-1][k]+1>dp[cur][j][k]){
                            changed=true;
                            dp[cur][j][k]=dp[last][j-1][k]+1;
                        }
                    }
                    // down neighbor
                    if (j<row-1){
                        if(map[j+1][k]>map[j][k]&&dp[last][j+1][k]+1>dp[cur][j][k]){
                            changed=true;
                            dp[cur][j][k]=dp[last][j+1][k]+1;
                        }
                    }
                }
            if (!changed)
                break;
        }

        int len=0;
        int last=(i-1)%2;
        for(int j=0;j<row;j++)
            for(int k=0;k<col;k++){
                //cout<<dp[i-1][j][k]<<' ';
                if(len<dp[last][j][k])len=dp[last][j][k];
            }
//        cout<<endl;
        cout<<len<<endl;
    }

    return 0;
}
