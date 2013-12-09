#include <iostream>

using namespace std;

typedef struct _cmate{
    int likes[2];
    int newpos;
    bool moved;
} cmate;

cmate arr[50000];
int diff[50000];

int mod(int a, int b){
    int r = a % b;
    if (r < 0) r += b;
    return r;
}

int main(){

    int N = 0;
    int n = 0;
    cin >> N;

    int c = -1;
    while (++c < N){
        cin >> n;
        int i = -1;
        while (++i < n){
            cin>>arr[i].likes[0]>>arr[i].likes[1];
            arr[i].likes[0] --;
            arr[i].likes[1] --;
        }

        bool fail = false;
        // check if A likes B but B hates A
        for (int j = 0; j < n; j ++){
            for (int k = 0; k < 2; k ++){
                int dest = arr[j].likes[k];
                if (arr[dest].likes[0] != j && arr[dest].likes[1] != j){
                    fail = true;
                    goto prefail;
                }
            }
        }
prefail:
        if (fail){
            cout << -1 << endl;
        }
        else{
            int cost = n;
            for (int j = 0; j < 2; j ++, fail = false){

                for (int k = 0; k < n; k ++){
                    arr[k].moved = false;
                    arr[k].newpos = k;
                }

                int current = 0;
                int pos = 0;
                int last = current;
                arr[0].moved = true;
                current = arr[current].likes[j];
                arr[current].newpos = ++pos;
                arr[current].moved = true;

                for (int k = 0; k < n-2; k ++){
                    int next;
                    if (!arr[arr[current].likes[0]].moved) 
                        next = arr[current].likes[0];
                    else if (!arr[arr[current].likes[1]].moved)
                        next = arr[current].likes[1];
                    else {
                        fail = true;
                        break;
                    }
                    last = current;
                    current = next;
                    arr[next].newpos = ++pos;
                    arr[next].moved = true;
                }

                if (!fail){
                    for (int k = 0; k < n; k ++){
                        diff[k] = 0;
                    }
                    for (int k = 0; k < n; k ++){
                        // cout << arr[k].newpos << ' ' << k << ' ' << mod(arr[k].newpos-k, n) << endl;
                        diff[mod(arr[k].newpos-k, n)]++;
                    }
                    int _cost = 0;
                    for (int k = 0; k < n; k ++){
                        if (_cost < diff[k]) _cost = diff[k];
                    }
                    _cost = n-_cost;
                    if (_cost < cost) cost = _cost;
                }
            } 
            cout << cost << endl;
        }
    }

    return 0;
}
