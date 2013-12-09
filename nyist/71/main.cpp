#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    int s;
    cin>>s;
    while (s--){
        deque<int> v;
        int w, n;
        cin>>w>>n;
        while (n--){
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        if (v.size() == 1){
            cout << 1 << endl;
        }
        else{
            sort(v.begin(), v.end());
            int count = 0;
            while (!v.empty()){
                count ++;
                int temp = v.back();
                v.pop_back();
                if (!v.empty() && w-temp>=v.front()) v.pop_front();
            }
            cout << count << endl;
        }
    }
    return 0;
}
