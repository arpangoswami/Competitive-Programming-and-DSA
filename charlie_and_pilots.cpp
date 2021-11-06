#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int pilots(int *c,int *a,int size,int diff,int **dp){
    if(size == 0){
        return 0;
    }
    if(dp[size][diff]!=-1){
        return dp[size][diff];
    }
    if(diff == 0){
        return dp[size][diff] = a[0] + pilots(c+1,a+1,size-1,diff+1,dp);
    }
    else if(diff == size){
        return dp[size][diff] = c[0] + pilots(c+1,a+1,size-1,diff-1,dp);
    }
    return dp[size][diff] = min(a[0]+pilots(c+1,a+1,size-1,diff+1,dp),c[0]+pilots(c+1,a+1,size-1,diff-1,dp));
}
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    int *c = new int[n]();
    int *a = new int[n]();
    int **dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[n/2 + 1];
        for(int j=0;j<=n/2;j++){
            dp[i][j] = -1;
        }
    }
    for(int i=0;i<n;i++){
        cin>>c[i]>>a[i];
    }
    cout<<pilots(c,a,n,0,dp)<<"\n";
    delete []c;
    delete []a;
    for(int i=0;i<=n;i++){
        delete []dp[i];
    }
    delete []dp;
    return 0;
}