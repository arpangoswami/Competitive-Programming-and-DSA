#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int *arr,int n){
        int i,j,temp,exchange = 0;
        for(i = 0;i < n-1; i++){
            exchange = 0;
            for(j = 0; j < n-1-i; j++){
                if(arr[j]>arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    exchange++;
                }
            }
            if(exchange==0){
                break;
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
    bubbleSort(arr,n);
    printf("After sorting the elements of the array are: \n");
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    free(arr);
}
