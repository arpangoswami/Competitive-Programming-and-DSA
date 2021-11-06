#include<stdio.h>
#include<stdlib.h>
void selectionSort(int *arr,int n){
    int i,min,j,temp;
    for(i=0 ; i<n-1 ; i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        if(i!=min){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
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
    selectionSort(arr,n);
    printf("After sorting the elements of the array are: \n");
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    free(arr);
}
