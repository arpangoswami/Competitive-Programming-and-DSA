#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        int tar = target - arr[i];
        for(int j = i+1;j<n;j++){
            if(arr[j] == target-arr[i]){
                cout<<arr[i]<<" and "<<arr[j]<<endl;
            }
        }
    }
}
