/*
Sad Life in Sales Problem Code: SADSALESolvedSubmit

 
Preface:
Trees have formed a core part of Graph Theory. Whether it be in form of Red-Black Trees in map, binary tree in heaps etc − trees form the fundamentals of multiple data structures.

What makes trees different from general graphs is the innumerable amount of special properties associated with them, which are otherwise lost in a general graph. Hence, study of Graph Theory feels always incomplete without trees.

Statement:
In a far away Galaxy of Tilky Way, there was a planet Tarth where the sport of Tompetitive Toding was very popular. According to legends, there lived a setter who loved DFS and giving complex Convex Hull Trick problems to unsuspecting candidates in TCDSAP (Todechef Certified Data Structure and Algorithms Program) examination.

Tima has been miserable all day!! She was not able to fetch a lot of sales for Todechef this quarter − even her rivals Tuchika, Teha and Tallavi were far ahead of her.

"They didn't even study sales!!" Tima sobbed. Now, Traveen is a man with heart of gold; hence, he decided to help Tima only because he is a good guy who believes in the power of rainbows, unicorns and goodie-goodie things in world.

He gave Tima the map of Tumbai, in the form of a weighted tree with N nodes, rooted at node R. The nodes are numbered from 1 to N. The edge from node u to node v had a weight w if Tima can pick up w coins by going from u to v and use them to increase her sales result. Tima is happy, and has Q queries, each asking "How many coins can I pick up if I go along the shortest path from node U to V?".

Now, since Traveen was not TCDSAP certified − he cannot find the answer to Tima's query. Its up to you to help him save his day!!

Input:
The first line contains T− Number of test cases in a file.
The first line of each test case has 3 integers − N Q and R - denoting Number of nodes, Number of Queries and the root node respectively.
Next N−1 lines have 3 integers each - u v w - denoting that there is an edge between u to v with w coins.
Next Q lines contain 2 integers - U and V - asking that "How many coins can Tima pick up if she goes from node U to node V".
Note- Input can be huge. Prefer fast IO methods.

Output:
For every query, print the number of coins Tima can pick, on a new line.

Constraints
1≤T≤10000
1≤N,Q≤105
1≤R,u,v,U,V≤N
1≤w≤109
Sum of N, Q over all T is ≤106
Subtasks
15% points - N,Q≤1000.
10% points - Graph is a Path Graph (ie. Line Graph)
15% points - Graph is a Binary Tree (ie. each node has at most two children)
60% points - Original Constraints
Sample Input:
1
3 1 1
1 2 5
1 3 4
2 3
Sample Output:
9
EXPLANATION:
We see that its a simple graph of 3 nodes rooted at Node 1 with Node 1 connected to Node 2 with edge of weight 5, and to node 3 with an edge of weight 4. The query asks coins picked up on going from 2 to 3 which is 5+4=9.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
void binary_lifting(int src,int par,vector<pii> adj_list[],vector<vector<int>> &up){
	up[src][0] = par;
	for(int i=1;i<20;i++){
		if(up[src][i-1] != -1){
			up[src][i] = up[up[src][i-1]][i-1];
		}else{
			up[src][i] = -1;
		}
	}
	for(pii x:adj_list[src]){
		if(x.first!=par){
			binary_lifting(x.first,src,adj_list,up);
		}
	}
}
int lift_node(int v,int k,vector<vector<int>> &up){
	if(v == -1 || k == 0){
		return v;
	}
	for(int i=19;i>=0;i--){
		if(v == -1 || k == 0){
			break;
		}
		if(k >= (1 << i)){
			v = up[v][i];
			k -= (1 << i);
		}
	}
	return v;
}
void bfs(int sv,int n,vector<pii> adj_list[],vector<int> &levels){
	levels[sv] = 0;
	queue<pii> q;
	q.push({sv,-1});
	while(!q.empty()){
		int node = q.front().first,par = q.front().second;
		q.pop();
		int lvl = levels[node];
		for(pii x:adj_list[node]){
			if(x.first!=par){
				q.push({x.first,node});
				levels[x.first] = lvl+1;
			}
		}
	}
}
int ans_query(int x,int y,vector<int> &levels,vector<vector<int>> &up){
	if(levels[x] > levels[y]){
		swap(x,y);
	}
	int lvl1 = levels[x],lvl2 = levels[y];
	int diff = lvl2 - lvl1;
	y = lift_node(y,diff,up);
	if(x == y){
		return x;
	}
	for(int i=19;i>=0;i--){
		if(up[x][i]!=up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
	}
	return lift_node(x,1,up);
}
void bfsDist(int root,int n,vector<pii> adj_list[],vector<int> &distances){
	distances[root] = 0;
	queue<pii> Q;
	Q.push({root,-1});
	while(!Q.empty()){
		pii temp = Q.front();
		Q.pop();
		int v = temp.first,par = temp.second;
		int dist = distances[v];
		for(pii x:adj_list[v]){
			int nb = x.first;
			int cost = x.second;
			if(par == nb){
				continue;
			}
			distances[nb] = dist + cost;
			Q.push({nb,v});
		}
	}
}
void solveQuestion(){
	int n,q,r;
	cin >> n >> q >> r;
	vector<pii> adj_list[n+1];
	vector<vector<int>> up(n+1,vector<int>(20,-1));
	vector<int> levels(n+1);
	vector<int> distances(n+1);
	for(int i=0;i<(n-1);i++){
		int x,y,coins;
		cin >> x >> y >> coins;
		adj_list[x].push_back({y,coins});
		adj_list[y].push_back({x,coins});
	}
	binary_lifting(r,-1,adj_list,up);
	bfs(r,n,adj_list,levels);
	bfsDist(r,n,adj_list,distances);
	while(q--){
		int x,y;
		cin >> x >> y;
		int lca = ans_query(x,y,levels,up);
		int dist1 = abs(distances[lca] - distances[x]);
		int dist2 = abs(distances[lca] - distances[y]);
		cout<<dist1 + dist2<<"\n";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
