#include<iostream>
using namespace std;
void merge(int arr[],int low,int mid,int high){
    int a[high-low+1];
    int i=low,j=mid,k=0;
    while(i<mid && j<=high){
        if(arr[i]<=arr[j]){
            a[k++] = arr[i++];
        }
        else{
            a[k++] = arr[j++];
        }
    }
    while(i<mid){
        a[k++] = arr[i++];
    }
    while(j<=high){
        a[k++] = arr[j++];
    }
    for(int i=low,k = 0;i<=high;i++,k++){
        arr[i] = a[k];
    }
}
void mergeSort(int a[],int low,int high){
    if(low>=high){
        return;
    }
    int mid = low+(high-low)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid+1,high);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
	return 0;
}
