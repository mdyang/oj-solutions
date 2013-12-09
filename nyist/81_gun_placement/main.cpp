#include <iostream>
#include <memory.h>

using namespace std;

int ground[101];
int dp[2][61][61];
int states[61];
int plat[61];
char s[11];

int main(){

    int X;
    cin >> X;

    while (X--){
        int N, M;
        cin >> N >> M;
        
        if (N == 0 || M==0) {
            cout << 0 << endl;
            continue;
        }

        memset(ground, 0, sizeof(ground));
        memset(dp, 0, sizeof(dp));
        memset(states, 0, sizeof(states));
        memset(plat, 0, sizeof(plat));
        memset(s, 0, sizeof(s));

        for (int i = 0; i < N; i ++){
            cin >> s;
            int _ground = s[0]=='H'?1:0;
            for (int j = 1; j < M; j ++){
                _ground <<= 1;
                if (s[j] == 'H') _ground++;
            }
            ground[i] = _ground;
        }

        int stateNum = 0;
        for (int i = 0; i < 1<<M; i ++){
            if (i&i<<1 || i&i<<2) continue;
            states[stateNum]=i;
            int j = 0;
            for (int k = 0; k<10;k++){
                if (i&1<<k)j++;
            }
            plat[stateNum] = j;
            stateNum++;
        }

        // calculate the first line
        for (int i = 0; i < stateNum; i ++){
            if (ground[0] & states[i]) continue;
            dp[0][i][0] = plat[i];
        }

        int row = 0;

        for (int i = 0; i < stateNum; i ++){
            if (ground[1] & states[i]) continue;
            for (int j = 0; j < stateNum; j ++){
                if (states[j] & ground[0]) continue;
                if (states[j] & states[i]) continue;
                dp[1][i][j] = dp[1][i][j] > dp[0][j][0]+plat[i] ? 
                    dp[1][i][j] : dp[0][j][0]+plat[i];
            }
        }

        row = 1;

        for (int i = 2; i < N; i ++){
            int nRow = (row+1)%2;
            // row i uses states[j]
            for (int j = 0; j < stateNum; j ++){
                if (ground[i] & states[j]) continue;
                // row i-1 uses states[k]
                for (int k = 0; k < stateNum; k ++){
                    // removing this line is okay, but will take more search time
                    if (ground[i-1] & states[k]) continue;
                    if (states[j]&states[k]) continue;
                    // row i-2 uses states[l]
                    for (int l = 0; l < stateNum; l ++){
                        // removing this line is okay, but will take more time
                        if (ground[i-2] & states[l]) continue;
                        if (states[j] & states[l]) continue;
                        dp[nRow][j][k] = dp[nRow][j][k] > dp[row][k][l]+plat[j]?
                            dp[nRow][j][k] : dp[row][k][l] + plat[j];
                    }
                }
            }
            row = nRow;
        }
       
        int maxNum = 0;

        for (int i = 0; i < stateNum; i ++){
            for (int j = 0; j < stateNum; j ++){
                if (maxNum < dp[row][i][j]) maxNum = dp[row][i][j];
            }
        }

        cout << maxNum << endl;
    }

    return 0;
}

