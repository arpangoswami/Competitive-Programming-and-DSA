#include<stdio.h>
#include<stdlib.h>
void quick(int *arr,int low,int up){
    int pivloc;
    if(low>=up)
        return;
    pivloc = partition(arr,low,up);
    quick(arr,low,pivloc-1);
    quick(arr,pivloc+1,up);
}
int partition(int *arr,int low,int up){
    int temp,i,j,pivot;
    i = low+1;
    j = up;
    pivot = arr[low];
    while(i<=j){
        while(arr[i] < pivot && (i<up)){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        else{
            i++;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
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
    quick(arr,0,n-1);
    printf("After sorting the elements of the array are: \n");
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    free(arr);
}
