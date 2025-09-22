/*searching

Linear search - no sorted array required
Binary search - sorted array required



*/


#include <stdio.h>
//sqrt of x
double Sqrt(int x)
{
    int s=1;
    int e=x;
    while(s<=e){
        double mid = s+(e-s)/2;
        double ans=mid*mid;
        if(ans<=x)
        {
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }
    return e;
}
int main()
{
    int x = 15;
    
    printf("the sqrt is %d ",Sqrt(x));
}
//question number 50 367 assignment

// 
//Binary Search
/*
int SortArray(){}

int BinarySearch(){}

int main(){
    int target=4;
    int arr[]={1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int starting = 0 ;
    int end = size-1;
    while(starting<size)
    {
        int mid = starting+(size-starting)/2;
        if(target==arr[mid])
        {
            printf("elment found at %d",mid) ;
        }
        else if(target>arr[mid])
        {
            starting=mid+1;
        }
        else 
        {
            size=mid-1;
        }
        starting++;
    }
    
}

*/
//Linear Search
/*

int LinearSearch(int *arr, int s, int target)
{
    int i;
    for (i=0;i<s; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

void DisplayArray(int *arr, int s, int target)
{
    printf("Taregt element :%d\n",LinearSearch(arr, s, target));
}

int main()
{

    int target = 10;
    int arr[] = {2, 3, 7, 1, 6, 9, 4, 5, 8};
    int *p = arr;
    int size = sizeof(arr) / sizeof(arr[0]);

    DisplayArray(p,size,target);
}
*/