#include<stdio.h>
#include<stdlib.h>
void merge(int *arr,int l,int mid,int r){
    int size1 = mid-l+1;
    int size2 = r - mid;
    int *left = (int *)malloc(size1*sizeof(int));
    int *right = (int *)malloc(size1*sizeof(int));
    int i=0,j=0,k=l;
    for(i=0;i<size1;i++){
        left[i] = arr[l+i];
    }
    for(j=0;j<size2;j++){
        right[j] = arr[mid+j+1];
    }
    i=0;
    j=0;
    while(i<size1 && j<size2){
        if(left[i]<right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }
    while(i<size1){
        arr[k++] = left[i++];
    }
    while(j<size2){
        arr[k++] = right[j++];
    }
    free(left);
    free(right);

}
void mergeSort(int *arr,int left,int right){
        if(left<right){
            int mid = (left+right)/2;
            mergeSort(arr,left,mid);
            mergeSort(arr,mid+1,right);
            merge(arr,left,mid,right);
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
    mergeSort(arr,0,n-1);
    printf("After sorting the elements of the array are: \n");
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    free(arr);
}
