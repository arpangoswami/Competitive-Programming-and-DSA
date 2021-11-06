#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void InsertHeap(int A[],int n){
    int temp = A[n],i = n;
    while(i>1 && temp>A[i/2]){
        A[i] = A[i/2];
        i/=2;
    }
    A[i] = temp;
}
void DeleteHeap(int A[],int n){
    int i = 1,j = 2*i;
    if(A[i]>A[n])
        swap(&A[1],&A[n]);
    while(j<n-1){
        if(A[j]<A[j+1]){
            j++;
        }
        if(A[i] < A[j]){
            swap(&A[i],&A[j]);
            i = j;
            j*=2;
        }
        else
            break;
    }
}
int main(void){
    int A[] = {0,5,10,30,20,35,40,15},i,k;
    for(i = 2;i <= 7;i++){
        InsertHeap(A,i);
    }
    printf("Heap after inserting all elements is:\n");
    for(i = 1;i<=7;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    for(i = 7;i>1;i--){
        DeleteHeap(A,i);
    }
    printf("Sorted array using heap sort is:\n");
    for(i = 1;i<=7;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
