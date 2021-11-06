#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long coun = 0;
    int i = 0,j = 1;
    while(j<n){
        if((arr[i]+k)<=arr[j]){
            coun+=(n-j);
            i++;
        }
        else
        j++;
    }
    cout<<coun<<endl;
}
