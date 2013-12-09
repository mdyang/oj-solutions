#include<iostream>
#include<algorithm>

using namespace std;

const unsigned int SIZE=501;

class i_c{
    public:
        int operator()(const int& a, const int& b){
            return a<b;
        }
};

// when comp is < => min_heap
// when comp is > => max_heap

template <class T, class comp>
class heap{
    public:
        heap();
        heap(unsigned int n);
        ~heap();
        void add(T elem);
        void pop_front();
        T front();
        void adjust_top();
        bool empty();
    protected:
        void adjust_last();
        int _length;
        T *_data;
        comp c; 
};

template <class T, class comp>
heap<T, comp>::heap():_length(0){
    _data = new T[SIZE];
}

template <class T, class comp>
heap<T, comp>::heap(unsigned int n):_length(0){
    _data = new T[n];
}

template <class T, class comp>
heap<T, comp>::~heap(){
    delete []_data;
}

template <class T, class comp>
bool heap<T, comp>::empty(){
    return _length==0;
}

template <class T, class comp>
void heap<T, comp>::add(T elem){
    _data[++_length]=elem;
    adjust_last();
}

template <class T, class comp>
void heap<T, comp>::pop_front(){
    _data[1]=_data[_length--];
    adjust_top();
}

template <class T, class comp>
T heap<T, comp>::front(){
    return _data[1];
}

template <class T, class comp>
void heap<T, comp>::adjust_top(){
    int i=1;
    while(i<=_length){
        int dest=i*2;
        if(dest>_length)break;
        // two sons
        if(dest+1<=_length)
            // right child smaller
            if(c(_data[dest+1],_data[dest])) dest++;
        if(c(_data[dest],_data[i]))
            swap(_data[dest],_data[i]);
        else break;
        i=dest;
    }
}

template <class T, class comp>
void heap<T, comp>::adjust_last(){
    int i=_length;
    while(i>1){
        if(c(_data[i],_data[i/2])){
            swap(_data[i],_data[i/2]);
        }
        i/=2;
    }
}

int main(){
    heap<int,i_c> h;
    h.add(4);
    h.add(3);
    h.add(5);
    while(!h.empty()){
        cout<<h.front()<<endl;
        h.pop_front();
    }
    return 0;
}
