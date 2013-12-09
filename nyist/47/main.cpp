#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[1001];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&arr[i]);
        sort(arr,arr+n);
        if(n==1||n==2){
            printf("%d\n",arr[n-1]);
            continue;
        }
        int t=0;
        int i=n;
        int a=arr[0];
        int b=arr[1];
        while(1){
            if(i==2){
                t+=(arr[1]);
                break;
            }
            if(i==3){
                t+=(arr[0]+arr[1]+arr[2]);
                break;
            }
            int z=arr[i-1];
            int y=arr[i-2];
            if(2*b>a+y){
                t+=(y+a+z+a);
            }
            else{
                t+=(b+a+z+b);
            }
            i-=2;
        }
        printf("%d\n",t);
    }
    return 0;
}
