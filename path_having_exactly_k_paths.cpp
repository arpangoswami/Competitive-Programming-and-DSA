#include <bits/stdc++.h>
using namespace std;
int dfs(int start,int finish,vector<vector<int>>& adj_mat,vector<bool> &visited,int e,int n){
    visited[start] = true;
    if(start == finish){
        visited[start] = false;
        if(e == 0 || adj_mat[start][start]){
            return 1;   
        }
        return 0;
    }
    if(e<=0){
        return 0;
    }
    int ct = 0;
    for(int i=0;i<n;i++){
        if(adj_mat[start][i] && !visited[i]){
            ct+=dfs(i,finish,adj_mat,visited,e-1,n);
        }
    }
    visited[start] = false;
    return ct;
}
int main() {
	//code
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    vector<vector<int>> adj_mat(n,vector<int>(n));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>adj_mat[i][j];
	        }
	    }
	    // for(int i=0;i<n;i++){
	    // 	for(int j=0;j<n;j++){
	    // 		cout<<adj_mat[i][j]<<" ";
	    // 	}
	    // 	cout<<"\n";
	    // }
	    int start,finish,edges;
	    cin>>start>>finish>>edges;
	    vector<bool> visited(n,false);
	    int ans = dfs(start,finish,adj_mat,visited,edges,n);
	    cout<<ans<<endl;
	}
	return 0;
}