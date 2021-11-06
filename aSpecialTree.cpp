#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
void dfs(int node, int par, vector<int> &specialNodes, vector<int> &specialNodeInSubTree, int lvl, vector<int> &levels, vector<int> adj_list[]) {
	levels[node] = lvl;
	if(specialNodes[node]){
		specialNodeInSubTree[node] = node;
	}
	for (int nb : adj_list[node]) {
		if (nb != par) {
			dfs(nb, node, specialNodes, specialNodeInSubTree, lvl + 1, levels, adj_list);
			if(specialNodeInSubTree[nb] != -1){
				specialNodeInSubTree[node] = specialNodeInSubTree[nb];
			}
		}
	}
}
void binary_lifting(int node, int par, vector<int> adj_list[], vector<vector<int>> &up) {
	up[node][0] = par;
	for (int i = 1; i < 20; i++) {
		if (up[node][i - 1] != -1)
			up[node][i] = up[up[node][i - 1]][i - 1];
		else
			up[node][i] = -1;
	}
	for (int nb : adj_list[node]) {
		if (nb != par) {
			binary_lifting(nb, node, adj_list, up);
		}
	}
}
int liftNode(int node, int jump_req, vector<vector<int>> &up) {
	for (int i = 19; i >= 0; i--) {
		if (node == -1 || jump_req == 0) {
			break;
		}
		if (jump_req >= (1 << i)) {
			node = up[node][i];
			jump_req -= (1 << i);
		}
	}
	return node;
}
int ans_query(int node, int jump_req, vector<vector<int>> &up) {
	if (node == -1 || jump_req == 0) {
		return node;
	}
	for (int i = 19; i >= 0; i--) {
		if (jump_req >= (1 << i)) {
			return ans_query(up[node][i], jump_req - (1 << i), up);
		}
	}
	return -1;
}
int calDist(int u, int v, vector<vector<int>> &up, vector<int> &levels) {
	if (levels[u] < levels[v]) {
		swap(u, v);
	}
	int diff = levels[u] - levels[v];
	u = liftNode(u, diff, up);
	if (u == v) {
		return diff;
	}
	int ans = diff;
	for (int i = 19; i >= 0; i--) {
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
			ans += (1 << (i + 1));
		}
	}
	return (ans + 2);
}
void solveQuestion() {
	int n, k, targetNode;
	cin >> n >> k >> targetNode;
	vector<int> specialNodes(n+1);
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		specialNodes[x] = 1;
	}
	vector<int> adj_list[n + 1];
	for (int i = 0; i < (n - 1); i++) {
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	vector<int> specialNodeInSubTree(n + 1, -1);
	vector<vector<int>> up(n + 1, vector<int>(20));
	vector<int> levels(n + 1);
	binary_lifting(targetNode, -1, adj_list, up);
	dfs(targetNode, -1, specialNodes, specialNodeInSubTree, 0, levels, adj_list);
	vector<int> distances(n + 1);
	vector<int> ansNode(n + 1);
	for (int i = 1; i <= n; i++) {
		int low = 0, high = levels[i], ans = targetNode;
		while (low <= high) {
			int mid = (low + high) / 2;
			int v = ans_query(i, mid, up);
			if (specialNodeInSubTree[v] != -1) {
				ans = v;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		int d1 = calDist(ans , targetNode, up, levels);
		int d2 = calDist(i, ans, up, levels);
		ansNode[i] = specialNodeInSubTree[ans];
		distances[i] = d1 - d2;
	}
	for (int i = 1; i <= n; i++) {
		cout << distances[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		cout << ansNode[i] << " ";
	}
	cout << "\n";
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	cin >> test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}