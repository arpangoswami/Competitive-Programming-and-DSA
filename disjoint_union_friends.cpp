#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<int,int> parent;
unordered_map<int,int> rankHeight;
int findParent(int x){
    if(x == parent[x]){
        return x;
    }
    int par = findParent(parent[x]);
    parent[x] = par;
    return par;
}
void unionByRank(int x,int y){
    int x_rep = findParent(x),y_rep = findParent(y);
    if(x_rep == y_rep) return;
    else if(rankHeight[x_rep]>rankHeight[y_rep]){
        parent[y_rep] = x_rep;
    }
    else if(rankHeight[y_rep]>rankHeight[x_rep]){
        parent[x_rep] = y_rep;
    }
    else{
        parent[y_rep] = x_rep;
        rankHeight[x_rep]++;
    }
}
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        parent[i] = i;
        rankHeight[i] = 1;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        unionByRank(u,v);
    }
    unordered_map<int,int> numberOfFriends;
    for(int i=1;i<=n;i++){
        numberOfFriends[findParent(i)]++;
    }
    vector<int> ans(n+1,0);
    for(int i=1;i<=n;i++){
        ans[i] = numberOfFriends[findParent(i)] - 1;
    }
    /*for(int i=1;i<=n;i++){
        cout<<findParent(i)<<" ";
    }
    cout<<"\n";*/
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
