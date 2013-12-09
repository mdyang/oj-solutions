#include <iostream>

using namespace std;

int mds(int y, int m){
    switch (m){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            if (y%400==0 || (y%100 && y%4==0)){
                return 29;
            }
            return 28;
    }
}

int doy(int y, int m, int d){
    int sum = 0;
    for (int i = 1; i < m; i ++) sum += mds(y, i);
    sum += d;
    return sum;
}


int main(){
    int n;
    cin >> n;
    while (n--){
        int y,m,d;
        cin >> y >> m >> d;
        cout << doy(y,m,d) << endl;
    }
}
