/*
Guide
Input file: standard input
Output file: standard output
Time limit: 3 seconds
Memory limit: 512 megabytes
Mister Gooti is the world-famous guide of The Freezing Isles. The topology of the Isles can be represented
as a tree with cities at the vertices and two-way roads between them. Gooti prepares a new sightseeing
tour over the Isles. He wants to find the shortest path that starts in the capital and visits k different
cities, including the capital. Please, help him.
Input
The first line of the input contains the number of tests T (1 ≤ T ≤ 100). Each test consists of two lines.
The first line contains the overall number of cities n in the Isles and the requested number of cities k for
the tour (1 ≤ k ≤ n ≤ 100). The second line contains the description of the tree in a rooted manner: n−1
integers where the i-th integer, pi
, is the parent of the city i + 1 (1 ≤ pi ≤ i). The capital is the city with
the number 1 — the root of the tree.
Output
For each test, the first line of the output shall contain the length of the path l. The second line shall
contain l + 1 integers — the cities that lie on the path in the order of the traversal.
Example
standard input standard output
3
6 2
1 1 2 2 3
6 6
1 1 2 2 3
6 4
1 2 3 4 5
1
1 2
8
1 3 6 3 1 2 5 2 4
3
1 2 3 4
Note
The following pictures illustrate all the three tests from the example.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<int> dist;
vector<int> par;
vector<int> adj_list[101];
vector<int> longestPath;
int rem;
set<int> verticesInDia;
int n,k;
void traceDia(pii dia){
	int lastVertex = dia.first;
	while(lastVertex > 0){
		longestPath.emplace_back(lastVertex);
		verticesInDia.insert(lastVertex);
		lastVertex = par[lastVertex];
	}
	reverse(longestPath.begin(),longestPath.end());
}
pii bfs(int sv){
	queue<pii> q;
	q.push({1,0});
	dist[1] = 0;
	par[1] = 0;
	while(!q.empty()){
		pii temp = q.front();
		q.pop();
		int v = temp.first,parent = temp.second;
		for(int x:adj_list[v]){
			if(x == parent){
				continue;
			}
			q.push({x,v});
			dist[x] = 1+dist[v];
			par[x] = v;
		}
	}
	int maxV = 1,maxDist = 0;
	for(int i=1;i<=n;i++){
		if(dist[i] > maxDist){
			maxV = i;
			maxDist = dist[i];
		}
	}
	return {maxV,maxDist};
}
void pathFinder(int sv){
	cout<<sv<<" ";
	for(int x:adj_list[sv]){
		if(x == par[sv] || verticesInDia.count(x) || rem == 0){
			continue;
		}
		otherPath = true;
		rem--;
		pathFinder(x);
		cout<<sv<<" ";
	}
}
void solveQuestion(){
	cin >> n >> k;
	verticesInDia.clear();
	longestPath.clear();
	dist.clear();
	par.clear();
	dist.resize(n+1);
	par.resize(n+1);
	rem = 0;
	for(int i=0;i<=n;i++){
		dist[i] = 0;
		par[i] = 0;
		adj_list[i].clear();
	}
	vi edges(n-1);
	for(int &i:edges){
		cin >> i;
	}
	for(int i=0;i<(n-1);i++){
		int v = edges[i];
		adj_list[v].push_back(i+2);
		adj_list[i+2].push_back(v);
	}
	pii dia = bfs(1);	
	if((k-1) <= dia.second){
		traceDia(dia);
		cout<<(k-1)<<'\n';
		for(int i=0;i<k;i++){
			cout<<longestPath[i]<<" ";
		}
		cout<<'\n';
	}else{
		traceDia(dia);
		rem = k-dia.second-1;
		cout<<2*rem + dia.second<<'\n';
		for(int x:longestPath){
			if(rem > 0){
				pathFinder(x);
			}else{
				cout<<x<<" ";
			}
		}
		cout<<'\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}