#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double sum = 0, temp;
    for (int i = 0; i < 12; i ++){
        cin>>temp;
        sum += temp;
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << sum/12 << endl;
}
