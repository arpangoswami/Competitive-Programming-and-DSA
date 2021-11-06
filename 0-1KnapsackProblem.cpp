#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> items;
int knapsack(int idx,int n,int bag_size,int picked,items *arr,int **dp){
    if(dp[idx][picked]!=-1) return dp[idx][picked];
    if(idx == n || bag_size == 0){
        return 0;
    }
    int ans = 0;
    if(arr[idx].first<=bag_size){
        ans = max(knapsack(idx+1,n,bag_size-arr[idx].first,picked+arr[idx].first,arr,dp)+arr[idx].second,knapsack(idx+1,n,bag_size,picked,arr,dp));
    }
    else
        ans = knapsack(idx+1,n,bag_size,picked,arr,dp);
    return dp[idx][picked] = ans;
}
int main(){
    int n,bag_size;
    cin>>bag_size>>n;
    items *arr = new items[n];
    int **dp = new int *[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[bag_size+1]();
        for(int j=0;j<=bag_size;j++){
            dp[i][j] = -1;
        }
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    cout<<knapsack(0,n,bag_size,0,arr,dp)<<endl;
    for(int i=0;i<=n;i++){
        delete []dp[i];
    }
    delete []dp;
    delete []arr;
    return 0;
}
