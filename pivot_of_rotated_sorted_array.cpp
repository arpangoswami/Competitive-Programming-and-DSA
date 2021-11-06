#include<bits/stdc++.h>
using namespace std;
int pivotElement(int* arr,int n){
    int s = 0,e = n-1;
    if(arr[s]<arr[e]){
        return -1;
    }
    while(s<=e){
        int mid = s + (e - s)/2;
        if(mid>0 && arr[mid-1]>arr[mid]){
            return mid - 1;
        }
        else if(arr[mid] < arr[e]){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return -1;
}
int main(int argc,char const* argv[]){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans = pivotElement(arr,n);
    cout<<ans<<endl;
    delete []arr; 
    return 0;
}