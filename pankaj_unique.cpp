#include<bits/stdc++.h>
#include<math.h>
#define ll long long int 
#define vi vector<int>
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define pl pair<long,long> 
#define pi pair<int,int>
#define vec vector
using namespace std;

unordered_map<ll,ll> curr;

void dfs(int vertex,vec<ll> &color,vec<vec<ll>> &adj,vec<bool> &visited,vec<ll> &res){
    visited[vertex]=true;
    if(!curr.count(color[vertex]))
        res.push_back(vertex);
    curr[color[vertex]]=1;
    for(auto it:adj[vertex]){
        if(!visited[it]){
            dfs(it,color,adj,visited,res);
        }
    }
}

int main() {
  ll t=1;
  //cin>>t;
  while(t--){
    ll n;
    cin>>n;
    vector<ll> color(n);
    for(int i=0;i<n;i++)
        cin>>color[i];
    vector<vector<ll>> adj(n);
    ll start,end;
    for(int i=0;i<n;i++){
        cin>>start>>end;
        adj[start-1].push_back(end-1);
        adj[end-1].push_back(start-1);
    }
    curr.clear();
    vector<bool> visited(n,false);
    vector<ll> res;
    dfs(0,color,adj,visited,res);
    sort(res.begin(),res.end());
    for(auto it:res)
        cout<<it+1<<endl;
  }
  return 0;
}