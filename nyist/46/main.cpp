#include <stdio.h>

int main(){
    int c;
    scanf("%d", &c);
    while(c--){
        int n;
        scanf("%d",&n);
        if (n==1) {
            printf("0\n");
            continue;
        }
        int count=0;
        while(n>>1){
            count ++;
            if (n&1) count++;
            n>>=1;
        }
        printf("%d\n", count);
    }
    return 0;
}
