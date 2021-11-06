#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
void countUp(int vertex,int level,int up,vector<int> &parent,vector<bool> &visited,int &ct){
	if(vertex == 0){
		return;
	}
	if(level == 0){
		if(!visited[vertex]){
			ct++;
			visited[vertex] = true;
		}
		countUp(parent[vertex],up-1,up,parent,visited,ct);
	}else{
		countUp(parent[vertex],level-1,up,parent,visited,ct);
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		int n,a,b;
		cin>>n>>a>>b;
		vector<int> parent(n+1);
		for(int i=2;i<=n;i++){
			cin>>parent[i];
		}
		parent[1] = 0;
		parent[0] = -1;
		int ct = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				vector<bool> visited(n+1,false);
				countUp(j,0,b,parent,visited,ct);
				countUp(i,0,a,parent,visited,ct);
			}
		}
		double ans = ((double)ct)/((double)n*n);
		cout<<fixed<<setprecision(6)<<"Case #"<<t<<": "<<ans<<"\n";
	}
	return 0;
}