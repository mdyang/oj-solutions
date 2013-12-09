#include<iostream>
#include<algorithm>

using namespace std;

const unsigned int SIZE=25;

typedef struct _fish{
    int f;
    int i;
}fish;

class i_c{
    public:
        // this operator is written in order to AC
        int operator()(const fish& a, const fish& b){
            // without whis line submission will WA...
            if (a.f==b.f) return a.i<b.i;
            return a.f>b.f;
        }
};

// when comp is < => min_heap
// when comp is > => max_heap

template <class T, class comp=i_c>
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

int curval,maxval;
int f[25],d[25],t[25];
int n,h;
int main(){
    t[0]=0;
    while(1){
        cin>>n;
        if(!n)break;
        cin>>h;
        h*=12;
        for(int i=0;i<n;i++)cin>>f[i];
        for(int i=0;i<n;i++)cin>>d[i];
        for(int i=1;i<n;i++)cin>>t[i];
        int max_val=0;
        int max_trace[25];
        // lake i as the last lake
        for(int i=0;i<n;i++){
            int temp_trace[25]={0};
            heap<fish> fh;
            // build the initial 
            for(int j=0;j<=i;j++){
                fish _f;
                _f.f=f[j];
                _f.i=j;
                fh.add(_f);
            }
            int _t=h;
            // subtract the time on the road from total time
            for(int j=0;j<=i;j++)_t-=t[j];
            if(_t<=0)break;
            int temp_val=0;
            // fish!
            while(_t){
                fish _maxf=fh.front();
                // no more fish
                if(!_maxf.f){
                    temp_trace[0]+=_t;
                    break;
                }
                fh.pop_front();
                temp_val+=_maxf.f;
                temp_trace[_maxf.i]++;
                // decrease fish in lake _i
                _maxf.f-=d[_maxf.i];
                if(_maxf.f<0)_maxf.f=0;
                fh.add(_maxf);
                _t--;
            }
            if(temp_val>max_val){
                max_val=temp_val;
                for(int i=0;i<n;i++)max_trace[i]=temp_trace[i];
            }
        }
        cout<<max_trace[0]*5;
        for(int i=1;i<n;i++)cout<<", "<<max_trace[i]*5;
        cout<<endl;
        cout<<"Number of fish expected: "<<max_val<<endl<<endl;
    }
    return 0;
}
