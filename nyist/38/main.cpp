//Prim algorithm
#include<iostream>
#include<algorithm>

using namespace std;

const unsigned int SIZE=501;

typedef struct _E{
    int from;
    int to;
    int len;
}E;
int f[SIZE];
int father(int x){
    return f[x]==x?x:f[x]=father(f[x]);
}

class comparator{
    public:
        int operator()(const E&a, const E&b){
            return a.len<b.len;
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
        void clear();
    protected:
        void adjust_last();
        int _length;
        T *_data;
        comp c; 
};

template <class T, class comp>
heap<T, comp>::heap():_length(0){
    _data=new T[SIZE];
}

template <class T, class comp>
heap<T, comp>::heap(unsigned int n):_length(0){
    _data=new T[n];
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
void heap<T, comp>::clear(){
    _length=0;
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

typedef heap<E, comparator> myheap;

myheap heaps[SIZE];

int main(){

    int c;
    cin>>c;
    myheap h(250000);
    while(c--){
        int v,e;
        cin>>v>>e;
        E emin;
        emin.len=101;
        for(int i=0;i<=v;i++){
            f[i]=i;
        }
        for(int i=0;i<SIZE;i++){
            heaps[i].clear();
        }
        h.clear();
        for(int i=0;i<e;i++){
            E ee;
            cin>>ee.from>>ee.to>>ee.len;
            if(ee.len<emin.len){
                emin.len=ee.len;
                emin.from=ee.from;
                emin.to=ee.to;
            }
            heaps[ee.from].add(ee);
            swap(ee.from,ee.to);
            heaps[ee.from].add(ee);
        }
        int len=emin.len;
        f[emin.from]=emin.to;
        while(!heaps[emin.from].empty()){
            h.add(heaps[emin.from].front());
            heaps[emin.from].pop_front();
        }
        while(!heaps[emin.to].empty()){
            h.add(heaps[emin.to].front());
            heaps[emin.to].pop_front();
        }
        while(!h.empty()){
            E ee=h.front();
            h.pop_front();
            int x=father(ee.from);
            int y=father(ee.to);
            if(x==y)continue;
            f[x]=y;
            len+=ee.len;
            while(!heaps[ee.to].empty()){
                h.add(heaps[ee.to].front());
                heaps[ee.to].pop_front();
            }
        }
        int out=0x7fffffff;
        for(int i=0;i<v;i++){
            int temp;cin>>temp;
            if(temp<out)out=temp;
        }
        cout<<out+len<<endl;
    }

    return 0;
}
