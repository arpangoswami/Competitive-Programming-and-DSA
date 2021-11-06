#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
ll modExpo(ll base,ll expo){
    if(expo == 0){
        return 1LL;
    }
    ll smallAns = modExpo(base,expo/2);
    ll largeAns = (smallAns * smallAns) % mod;
    if(expo % 2 == 0){
        return largeAns;
    }
    return (largeAns * base) % mod;
}
ll ans;
ll dfs(ll sv,ll par,vector<int> adj_list[]){
    ll cnt = 1;
    for(int x:adj_list[sv]){
        if(x!=par){
            cnt += dfs(x,sv,adj_list);
        }
    }
    if(cnt > 1){
        ans++;
    }
    return cnt;
}
ll kingdomDivision(int n, vector<int> adj_list[]) {
    if(n == 1){
        return 2;
    }
    ans = 0;
    dfs(1,-1,adj_list);
    //cout<<ans<<"\n";
    return modExpo(2LL,ans);
}

int main()
{

    int n;
    cin >> n;
    vector<int> adj_list[n+1];
    for(int i=0;i<(n-1);i++){
        int u,v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    cout<<kingdomDivision(n,adj_list)<<"\n";
    return 0;
}
