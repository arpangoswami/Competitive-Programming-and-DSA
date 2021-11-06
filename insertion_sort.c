#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *arr,int size){
    int i,key,j;
    for(i=1;i<size;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j] ;
            j--;
        }
        arr[j+1] = key;
    }
}
int main(void){
    int n,i,element,flag = 0;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    printf("Enter the array elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,n);
    printf("After sorting the elements of the array are: \n");
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    free(arr);
}
