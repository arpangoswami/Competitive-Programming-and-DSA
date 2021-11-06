#include<stdio.h>
#include<stdlib.h>
int main(void){
    int n,i,element,flag = 0;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    printf("Enter the array elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched: \n");
    scanf("%d",&element);
    for(i=0;i<n;i++){
        if(arr[i] == element){
            flag=1;
            break;
        }
    }
    if(flag){
        printf("Element found at %d position",(i+1));
    }
    else{
        printf("Element not found");
    }
    free(arr);
}
