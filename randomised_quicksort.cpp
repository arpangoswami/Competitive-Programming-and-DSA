#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void shuffle(int *arr,int s,int e){
    srand(time(NULL));
    int i,j,temp;
    for(int i=e;i>0;i--){
        j = rand()%(i+1);
        swap(arr[i],arr[j]);
    }
}
int partit(int *arr,int s,int e){
    int pivot = arr[e];
    int i = s-1,j = s;
    for(;j<e;j++){
        if(arr[j]<=pivot){
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}
void quickSort(int *arr,int s,int e){
    if(s>=e){return;}
    int i = partit(arr,s,e);
    quickSort(arr,s,i-1);
    quickSort(arr,i+1,e);
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    shuffle(arr,0,n-1);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete []arr;
    return 0;
}
