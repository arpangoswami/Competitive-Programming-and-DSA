/*
https://codeforces.com/contest/1336/problem/A
A. Linova and Kingdom
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Writing light novels is the most important thing in Linova's life. Last night, Linova dreamed about a fantastic kingdom. She began to write a light novel for the kingdom as soon as she woke up, and of course, she is the queen of it.

There are n cities and n−1 two-way roads connecting pairs of cities in the kingdom. From any city, you can reach any other city by walking through some roads. The cities are numbered from 1 to n, and the city 1 is the capital of the kingdom. So, the kingdom has a tree structure.

As the queen, Linova plans to choose exactly k cities developing industry, while the other cities will develop tourism. The capital also can be either industrial or tourism city.

A meeting is held in the capital once a year. To attend the meeting, each industry city sends an envoy. All envoys will follow the shortest path from the departure city to the capital (which is unique).

Traveling in tourism cities is pleasant. For each envoy, his happiness is equal to the number of tourism cities on his path.

In order to be a queen loved by people, Linova wants to choose k cities which can maximize the sum of happinesses of all envoys. Can you calculate the maximum sum for her?

Input
The first line contains two integers n and k (2≤n≤2⋅105, 1≤k<n)  — the number of cities and industry cities respectively.

Each of the next n−1 lines contains two integers u and v (1≤u,v≤n), denoting there is a road connecting city u and city v.

It is guaranteed that from any city, you can reach any other city by the roads.

Output
Print the only line containing a single integer  — the maximum possible sum of happinesses of all envoys.

Examples
inputCopy
7 4
1 2
1 3
1 4
3 5
3 6
4 7
outputCopy
7
inputCopy
4 1
1 2
1 3
2 4
outputCopy
2
inputCopy
8 5
7 5
1 7
6 1
3 7
8 3
2 1
4 5
outputCopy
9
Note


In the first example, Linova can choose cities 2, 5, 6, 7 to develop industry, then the happiness of the envoy from city 2 is 1, the happiness of envoys from cities 5, 6, 7 is 2. The sum of happinesses is 7, and it can be proved to be the maximum one.



In the second example, choosing cities 3, 4 developing industry can reach a sum of 3, but remember that Linova plans to choose exactly k cities developing industry, then the maximum sum is 2.
*/
#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
typedef long long ll;
vector<int> adj_list[MAXN];
int happiness[MAXN];
int depth[MAXN] = {0};
int dfs(int v, int par) {
	depth[v] = depth[par] + 1;
	int ans = 1;
	for (int x : adj_list[v]) {
		if (x == par) {
			continue;
		}
		ans += dfs(x, v);
	}
	happiness[v] = ans - depth[v];
	return ans;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < (n - 1); i++) {
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	dfs(1, 0);
	nth_element(happiness + 1, happiness + n - k, happiness + n + 1, greater<int>());
	ll s = 0;
	for (int i = 1; i <= n - k; i++) {
		s += happiness[i];
	}
	cout << s << endl;
	return 0;
}