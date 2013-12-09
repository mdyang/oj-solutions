#include <iostream>
#include <set>

using namespace std;

typedef long long LLONG;

int main(){

    int c;
    cin>>c;
    while (c--){
        multiset<LLONG> s;
        int n;
        cin >> n;
        LLONG temp;
        for (int i = 0; i < n; i ++){
            cin>>temp;
            s.insert(temp);
        }
        if (n == 1) cout<<temp<<endl;
        else{
            LLONG price = 0;
            while (1){
                LLONG s1 = *s.begin();
                s.erase(s.begin());
                LLONG s2 = *s.begin();
                s.erase(s.begin());
                price += (s1+s2);
                if (s.size() == 0) break;
                s.insert(s1+s2);
            }
            cout << price << endl;
        }
    }

    return 0;
}
