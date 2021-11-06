#include<bits/stdc++.h>
using namespace std;
//long dp[4][4];
long maximumProfit(int idx,int n,int c1,int c2,long sumTillNow,long *arr1,long *arr2){
    if(idx==n){
        return sumTillNow;
    }
    long ans = INT_MIN;
    if(c1==3){
        ans =  maximumProfit(idx+1,n,0,c2+1,sumTillNow+arr2[idx],arr1,arr2);
    }
    if(c2==3){
        ans =  maximumProfit(idx+1,n,c1+1,0,sumTillNow+arr1[idx],arr1,arr2);
    }
    else
        ans =  max(maximumProfit(idx+1,n,0,c2+1,sumTillNow+arr2[idx],arr1,arr2),maximumProfit(idx+1,n,c1+1,0,sumTillNow+arr1[idx],arr1,arr2));
    return ans;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        long *arr1 = new long[n];
        long *arr2 = new long[n];
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
        }
        long ans = maximumProfit(0,n,0,0,0,arr1,arr2);
        cout<<ans<<endl;
        delete []arr1;
        delete []arr2;
    }
}
