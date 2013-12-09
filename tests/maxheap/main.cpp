#include <iostream>
#include <set>
#include <cstdlib>

using namespace std;

class topk_max_heap{
    int *_data;
    int _length;
    int _max_length;

    public:
    topk_max_heap(int);
    ~topk_max_heap();
    void add(int);
    const int* get_data();
};

class comparator{
    public:
        bool operator()(const int a, const int b){
            return (a > b);
        }
};

int main(int argc, char** argv){

    if (argc == 1){
        cout << "[cmd] [iter] [k] (should have iter > k)" << endl;
        return 0;
    }

    int iter = atoi(argv[1]);
    int k = atoi(argv[2]);

    cout << "Starting test for k=" << k
        << " and iter=" << iter << endl;

    set<int, comparator> smin;
    topk_max_heap heap(k);
    
    while (iter-- > 0){
        int r = rand();
        // cout << r << endl;
        smin.insert(r);

        heap.add(r);

        while (smin.size() > k){
            smin.erase(smin.begin());
        }
    }

    set<int> s_heap;
    const int* _data = heap.get_data();
    for (int i = 0; i < k; i ++){
        s_heap.insert(_data[i]);
    }

    bool passed = true;
    for (set<int, comparator>::iterator i = smin.begin(); i != smin.end(); i ++){
        if (s_heap.find(*i) == s_heap.end()){
            passed = false;
            cerr << *i << " doesn't exist in the topk_max_heap as expected." << endl;
        }
    }

    if (passed) cout << "Test passed." << endl;
    else{
        cerr << "Test failed for the error above." << endl;
        const int* _data = heap.get_data();
        cout << "Max heap data" << endl;
        for (int i = 0; i < k; i ++) cout << _data[i] << endl;
        cout << "Set data" << endl;
        for (set<int, comparator>::iterator i = smin.begin(); i != smin.end(); i ++)
            cout << *i << endl;
    }

    return 0;
}

topk_max_heap::topk_max_heap(int n): 
    _length(0),
    _max_length(n){

    _data = new int[n+1];
}

topk_max_heap::~topk_max_heap(){
    delete []_data;
}

void topk_max_heap::add(int n){
    if (_length < _max_length){
        _data[++_length] = n;
        int i = _length;
        while (i > 1){
            if (_data[i] > _data[i/2]){
                int temp = _data[i];
                _data[i] = _data[i/2];
                _data[i/2] = temp;
            }
            i /= 2;
        }
    }
    else{
        if (n < _data[1]){
            _data[1] = n;
            int i = 1;
            while (i <= _length){
                if (((i*2+1 <= _length) && (_data[i*2] > _data[i*2+1]) && (_data[i*2] > _data[i])) || 
                        ((i*2 <= _length) && (i*2+1 > _length) && (_data[i*2] > _data[i]))){
                    int temp = _data[i];
                    _data[i] = _data[i*2];
                    _data[i*2] = temp;
                    i *= 2;
                }
                else if ((i*2+1 <= _length) && (_data[i*2] < _data[i*2+1]) && (_data[i*2+1] > _data[i])){
                    int temp = _data[i];
                    _data[i] = _data[i*2+1];
                    _data[i*2+1] = temp;
                    i *= 2; i ++;
                }
                else break;
            }
        }
    }
}

const int* topk_max_heap::get_data(){
    return &_data[1];
}
