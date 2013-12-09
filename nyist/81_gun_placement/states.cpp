#include <iostream>

using namespace std;

int main(){

    int j = 0;

    for (int i = 0; i < 1000; i ++){
        if (i&i<<1 || i&i<<2) continue;
        j++;
    }

    cout << j << endl;

    return 0;
}
