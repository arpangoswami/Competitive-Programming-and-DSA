#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n,q;
    cin>>n>>q;
    int *arr = new int[n],*upto_def = new int[n]();
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<(n-1);i++){
        if((arr[i]>=arr[i-1] && arr[i]>=arr[i+1])||(arr[i]<=arr[i-1] && arr[i]<=arr[i+1])){
            upto_def[i] = upto_def[i-1]+1;
        }
        else{
            upto_def[i] = upto_def[i-1];
        }
    }
    upto_def[n-1] = upto_def[n-2];
    while(q--){
        int left,right;
        cin>>left>>right;
        int num_def = upto_def[right-2] - upto_def[left-1];
        if(num_def%2==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
