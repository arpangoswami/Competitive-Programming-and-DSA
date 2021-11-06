#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
bool pathExist(int sv,int dest,vector<int> *adj_list,vector<bool> &visited){
	if(sv == dest){
		return true;
	}
	visited[sv] = true;
	for(int x:adj_list[sv]){
		if(!visited[x]){
			bool f = pathExist(x,dest,adj_list,visited);
			if(f){
				return true;
			}
		}
	}
	visited[sv] = false;
	return false;
}
int32_t main(int32_t argc, char const* argv[]) {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin >> test;
	for (int t = 1; t <= test; ++t) {
		cout << "Case #" << t << ": " << "\n";
		int n;
		cin >> n;
		string incoming,outgoing;
		cin >> incoming;
		cin >> outgoing;
		vector<int> *adj_list = new vector<int>[n]();
		for(int i=0;i<n;i++){
			if(outgoing[i] == 'Y'){
				if(i!=0 && incoming[i-1] == 'Y'){
					adj_list[i].push_back(i-1);
				}
				if(i!=n-1 && incoming[i+1] == 'Y'){
					adj_list[i].push_back(i+1);
				}
			}
		}
		vector<vector<char>> possible(n,vector<char>(n));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				vector<bool> visited(n,false);
				bool f = pathExist(i,j,adj_list,visited);
				possible[i][j] = f ? 'Y' : 'N';
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<possible[i][j];
			}
			if(t == test && i == n-1){
				continue;
			}
			cout<<"\n";
		}
		delete []adj_list;
	}
	return 0;
}