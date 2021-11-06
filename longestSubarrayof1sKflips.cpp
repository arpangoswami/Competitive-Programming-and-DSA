#include<bits/stdc++.h>
using namespace std;
/*int maxSubarray(int idx,int n,int k,int *arr,int length,int maxLength,int **dp){
    if(dp[idx][k]!=-1) return dp[idx][k];
    if(idx==n){
        return dp[idx][k] = maxLength;
    }
    if(arr[idx]==0 && k>0){
        return dp[idx][k] = max(maxSubarray(idx+1,n,k-1,arr,length+1,max(maxLength,length+1),dp),maxSubarray(idx+1,n,k,arr,0,maxLength,dp));
    }
    if(arr[idx]==1){
        return dp[idx][k] = maxSubarray(idx+1,n,k,arr,length+1,max(maxLength,length+1),dp);
    }
    return dp[idx][k] = maxSubarray(idx+1,n,k,arr,0,maxLength,dp);
}*/
int main(){
    int n,k;
    cin>>n>>k;
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int maxLength = 0,right = 0,left = 0,zero_count = 0;
    while(right<n){
        if(arr[right] == 0){
            zero_count++;
        }
        while(zero_count>k){
            if(arr[left]==0) zero_count--;
            left++;
        }
        maxLength = max(maxLength,right-left+1);
        right++;
    }
    cout<<maxLength<<endl;
    int zeroWindow = 0;
    for(int i=0;i<maxLength;i++){
        if(arr[i]==0) zeroWindow++;
    }
    /*
    10 2
    1 0 0 1 0 1 0 1 0 1*/
    if(zeroWindow<=k){
        for(int i=0;i<maxLength;i++){
            if(arr[i]==0) {
                    //arr[i] = 1;
                    cout<<i<<" ";
            }
        }
    }
    else{
        int r = maxLength,l = 0,i;
        for(i = r;i<n;i++){
            if(arr[i] == 0){
                zeroWindow++;
            }
            if(arr[l] == 0){
                zeroWindow--;
            }
            l++;
            if(zeroWindow<=k) break;
        }
        for(int j=l;j<i;j++){
            if(arr[j]==0) arr[j] = 1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete []arr;
}
