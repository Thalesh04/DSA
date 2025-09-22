#include <stdio.h>
int main() {
    int n, arr[100], i, max, min;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    max = min = arr[0];
    for(i=1;i<n;i++) {
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    printf("Largest: %d\nSmallest: %d\n", max, min);
    return 0;
}