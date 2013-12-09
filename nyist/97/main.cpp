#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int N;
    cin >> N;
    while (N--){
        double m,x,y,z;
        cin >> m >> x >> y >> z;
        double distance = m*x;
        double time = distance / (y-x);
        double dog_d = time * z;
        cout << setiosflags(ios::fixed) << setprecision(2) << dog_d << endl;
    }
    return 0;
}
