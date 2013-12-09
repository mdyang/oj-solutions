#include <stdio.h>

typedef unsigned long long ull;

int ten[8];
int count[8];

int main(){

    int c;

    ten[0] = 1;
    for(int i=1;i<8;i++) ten[i]=ten[i-1]*10;

    count[1] = 1; int sum = 1;
    for(int i=2;i<8;i++) {
        count[i]=9*(sum+i-1)+1;
        printf("%d\n", count[i]);
        sum+=count[i];
    }

    scanf("%d",&c);
    while(c--){
        ull m;
        scanf("%lld",&m);
        if(m==0){
            printf("0\n");
            continue;
        }
        int mag=7;
        for(;mag>=0;mag--){
            if (m/ten[mag]>0) break;
        }
        printf("%d\n", mag);
        int res=0;
        for(;m&&mag>=1;mag--){
            ull div=m/ten[mag];
            ull rem=m%ten[mag];
            res+=div*(mag+count[mag]);
            if (div>=5) res++;
            m=rem;
        }
        if (m>=5) res++;
        printf("%d\n",res);
    }    

    return 0;
}
