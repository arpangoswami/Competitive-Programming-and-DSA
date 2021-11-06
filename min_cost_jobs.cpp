#include<bits/stdc++.h>
using namespace std;
int min_cost(int **cost,int n,int person,int mask,int *dp){
    if(person==n)
        return 0;
    if(dp[mask]!=INT_MAX)
        return dp[mask];
    int minimum=INT_MAX;
    for(int i=0;i<n;i++){
        if(!(mask&(1<<i))){
            int ans = min_cost(cost,n,person+1,(mask|(1<<i)),dp)+cost[person][i];
            if(ans<minimum)
                minimum=ans;
        }
    }
    dp[mask] = minimum;
    return minimum;
    /*
    4
    10 2 6 5
    1 15 12 8
    7 8 9 3
    15 13 4 10
    */
}
int min_cost_iter(int **cost,int n){


}
int main(void){
    int n;
    cin>>n;
    int **cost=new int *[n];
    for(int i=0;i<n;i++){
        cost[i]=new int [n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }
    int *dp=new int [1<<n];
    for(int i=0;i<(1<<n);i++){
        dp[i]=INT_MAX;
    }
    int mask=0;
    cout<<min_cost(cost,n,0,mask,dp);
}
