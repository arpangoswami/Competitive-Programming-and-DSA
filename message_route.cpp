#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
void tracePath(int fv,vector<int> &mp){
	vector<int> arr;
	while(fv!=-1){
		arr.push_back(fv);
		fv = mp[fv];
	}
	for(int i=arr.size()-1;i>=0;i--){
		cout<<arr[i]<<" ";
	}
}
void bfs(int sv,int n,vector<int>* adj_list){
	vector<bool> visited(n+1,false);
	vector<int> mp(n+1);
	mp[sv] = -1;
	visited[sv] = true;
	queue<pii> q;
	q.push({sv,1});
	bool f = false;
	int dist = -1;
	while(!q.empty()){
		pii temp = q.front();
		q.pop();
		int nod = temp.first,cmp = temp.second;
		if(nod == n){
			dist = cmp;
			f = true;
			break;
		}
		for(int x:adj_list[nod]){
			if(!visited[x]){
				mp[x] = nod;
				q.push({x,cmp+1});
				visited[x] = true;
			}
		}
	}
	if(!f){
		cout<<"IMPOSSIBLE"<<"\n";
	}else{
		cout<<dist<<"\n";
		tracePath(n,mp);
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int> *adj_list = new vector<int>[n+1]();
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	bfs(1,n,adj_list);
	delete []adj_list;
	return 0;
}