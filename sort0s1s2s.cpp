#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int *arr = new int[n],low = 0,mid = 0,high = n-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(mid<=high){
        if(arr[mid] == 0) swap(arr[low++],arr[mid++]);
        else if(arr[mid] == 1) mid++;
        else swap(arr[mid],arr[high--]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
