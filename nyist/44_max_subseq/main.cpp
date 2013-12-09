#include <stdio.h>

int largest(int* arr, int n){
    int maxSum = 0, tempMax = 0;
    maxSum = arr[0];

    for(int i=0;i<n;i++){
        if (maxSum < arr[i]) maxSum = arr[i];
    }

    if (maxSum <= 0) return maxSum;

    int tempSum = 0;
    for (int i=0; i<n;i++){
        tempSum+=arr[i];
        if(tempSum<0){
            tempSum=0;
            continue;
        }
        if (tempSum>maxSum)maxSum=tempSum;
    }
    return maxSum;
}

int arr[1000001];

int main(){

    int N, n;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &n);
        for (int i=0;i<n;i++) scanf("%d",&arr[i]);
        printf("%d\n", largest(arr, n));
    }

    return 0;

}
