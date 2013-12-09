#include<iostream>
#include<memory.h>
using namespace std;

bool isprime[1000000];
int primes[100000];
short paircount[1000000];

int count=0;

void make_prime(){
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    //for(int i=0;i<1000000;i++)cout<<isprime[i]<<'-';
    for(int i=2;i<1000000;i++){
        if(isprime[i])primes[count++]=i;
        for(int j=0;j<count&&i*primes[j]<1000000;j++){
            isprime[i*primes[j]]=false;
            if(i%primes[j]==0)break;
        }
    }
    //for(int i=0;i<count;i++)cout<<primes[i]<<' ';
    //cout<<endl;
}

int main(){
    make_prime();
    paircount[0]=paircount[1]=paircount[2];
    paircount[3]=1;
    int c=1;
    for(int i=4;i<1000000;i++){
        if(isprime[i]){
            if(isprime[i-2])c++;
        }
        paircount[i]=c;
    }
    //for(int i=1;i<1000000;i++){
    //    cout<<paircount[i]<<' ';
    //}
    
    cin>>c;
    while(c--){
        int temp;
        cin>>temp;
        cout<<paircount[temp]<<endl;
    }

    return 0;
}
