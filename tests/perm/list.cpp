#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.insert(l.begin(), 3);
    l.insert(l.begin(), 4);
    *l.begin() = 9;
    for (list<int>::iterator i = l.begin(); i != l.end(); i ++) cout << *i << endl;
    cout << *l.erase(l.begin()) << endl;
    return 0;
}
