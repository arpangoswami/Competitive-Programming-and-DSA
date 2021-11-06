#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
void bfs(int vertex, vector<int> *adj_list, map<int, vector<int>> &mp) {
	queue<pii> q;
	visited[vertex] = true;
	q.push({vertex, -1});
	while (!q.empty()) {
		pii temp = q.front();
		q.pop();
		int from = temp.second;
		int to = temp.first;
		if (from != -1) {
			mp[from].push_back(to);
		}
		for (int nb : adj_list[to]) {
			if (!visited[nb]) {
				visited[nb] = true;
				q.push({nb, to});
			}
		}
	}
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	vector<int> dep(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> dep[i];
	}
	vector<int> *adj_list = new vector<int>[n + 1]();
	//vector<int> *adj_T = new vector<int> [n+1]();
	vector<int> sinks;
	for (int i = 1; i <= n; i++) {
		if (dep[i] == -1) {
			sinks.push_back(i);
		} else {
			adj_list[i].push_back(dep[i]);
			//adj_T[dep[i]].push_back(i);
		}
	}
	vector<int> last;
	int ans = 0;
	vector<int>path;
	map<int, vector<int>> mp;
	vector<bool> visited(n + 1, false);
	for (int x : sink) {
		bfs(x, adj_list, mp);
	}
	for (auto it : mp) {
		int v = it.first;
		vi others = it.second;
		if (others.size() == 0) {
			last.push_back(v);
		}

	}
	for (int x : sink) {
		if(st.count(x) == 0){
			ans += arr[x];
		path.push_back(x);
		}
		
	}
	for (int x : last) {
		if (st.count(x) == 0) {
			ans += arr[x];
			path.push_back(x);
		}
	}
	cout << ans << "\n";
	for (int x : path) {
		cout << x << " ";
	}
	delete []adj_list;
	//delete []adj_T;
	return 0;
}