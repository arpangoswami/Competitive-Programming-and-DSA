#include<bits/stdc++.h>
using namespace std;
int dp[2001][2001];
int wineProblem(int be,int en,int arr[],int yr){
    if(be>en){
        return 0;
    }
    if(dp[be][en]!=-1){
        return dp[be][en];
    }
    int ans1 = arr[be]*yr+wineProblem(be+1,en,arr,yr+1);
    int ans2 = arr[en]*yr + wineProblem(be,en-1,arr,yr+1);
    int ans = max(ans1,ans2);
    dp[be][en] = ans;
    return ans;
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<wineProblem(0,n-1,arr,1);
    return 0;
}
