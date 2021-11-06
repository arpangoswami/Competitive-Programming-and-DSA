#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
typedef long long ll;
int arr[101];
ll dp[101][101];
ll sum(int i,int j){
    ll ans = 0;
    for(int k=i;k<=j;k++){
        ans = (ans+arr[k])%100;
    }
    return ans;
}
ll solveMixtures(int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for(int k=i;k<=j;k++){
        dp[i][j] = min(dp[i][j],solveMixtures(i,k) + solveMixtures(k+1,j) + sum(i,k)*sum(k+1,j));
    }
    return dp[i][j];
}
int main(){
    int n;
    while((scanf("%d",&n))!=EOF){
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<solveMixtures(0,n-1)<<endl;
    }
    return 0;
} 