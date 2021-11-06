#include<bits/stdc++.h>
using namespace std;
long dp[2001][2001][6];
long kOrderedLcs(int m,int n,int k,int *arr1,int *arr2){
    if(m<0 || n<0){
        return 0;
    }
    if(dp[m][n][k]!=-1){
        return dp[m][n][k];
    }
    long res = 0;
    if(arr1[m]!=arr2[n]){
        if(k>0){
            res = max(1+kOrderedLcs(m-1,n-1,k-1,arr1,arr2),max(kOrderedLcs(m-1,n,k,arr1,arr2),kOrderedLcs(m,n-1,k,arr1,arr2)));
        }
        else{
            res = max(kOrderedLcs(m,n-1,k,arr1,arr2),kOrderedLcs(m-1,n,k,arr1,arr2));
        }
    }
    else{
        res = 1+kOrderedLcs(m-1,n-1,k,arr1,arr2);
    }
    dp[m][n][k] = res;
    return res;
}
int main(){
    int n,m,k;
    cin>>m>>n>>k;
    memset(dp,-1,sizeof(dp));
    int *arr1 = new int[m];
    int *arr2 = new int[n];
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    long ans = kOrderedLcs(m-1,n-1,k,arr1,arr2);
    delete []arr1;
    delete []arr2;
    cout<<ans<<endl;
    return 0;
}
