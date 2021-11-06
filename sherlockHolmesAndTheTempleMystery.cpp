#include<bits/stdc++.h>
using namespace std;
int dp[101][10001];
int templeMystery(int s1,int s2,int idx,int *arr,int n){
    if(dp[idx][s2]!=-1 || dp[idx][s1]!=-1){
        if(dp[idx][s2]!=-1){
            return dp[idx][s2];
        }
        else{
            return dp[idx][s1];
        }
    }
    if(idx==n){
        if(s1==s2){
            dp[idx][s1] = 1;
            dp[idx][s2] = 1;
            return 1;
        }
        else{
            dp[idx][s2] = 0;
            dp[idx][s1] = 0;
            return 0;
        }
    }
    //return templeMystery(s1+arr[idx],s2,idx+1,arr,n) | templeMystery(s1,s2+arr[idx],idx+1,arr,n);
    int ans1 = templeMystery(s1+arr[idx],s2,idx+1,arr,n);
    int ans2 = templeMystery(s1,s2+arr[idx],idx+1,arr,n);
    dp[idx][s2] = ans1|ans2;
    dp[idx][s1] = ans1|ans2;
    return dp[idx][s2];
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool flag = templeMystery(0,0,0,arr,n);
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        delete []arr;
    }
}
