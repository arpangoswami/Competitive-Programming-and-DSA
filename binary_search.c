#include<stdio.h>
#include<stdlib.h>
int binarySearch(int *arr,int left,int right,int value){
    if(left>right)
        return (-1);
    int mid = (left+right)/2;
    if(arr[mid] == value){
        return (mid+1);
    }
    else if(arr[mid] > value){
        return binarySearch(arr,left,mid-1,value);
    }
    else{
        return binarySearch(arr,mid+1,right,value);
    }
}
int main(void){
    int n,i,element,index;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    printf("Enter the array elements in a sorted manner: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the value to be searched: \n");
    scanf("%d",&element);
    index = binarySearch(arr,0,n-1,element);
    if(index == -1){
        printf("Search was unsuccessful. \n");
    }
    else{
        printf("Value %d present at %d position. \n",(element,index));
    }

    free(arr);
}
