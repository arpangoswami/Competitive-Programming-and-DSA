/*11686 - Pick up sticks
Pick up sticks is a fascinating game.
A collection of coloured sticks are
dumped in a tangled heap on the
table. Players take turns trying
to pick up a single stick at a time
without moving any of the other
sticks. It is very difficult to pick up
a stick if there is another stick lying
on top of it. The players therefore
try to pick up the sticks in an order
such that they never have to pick
up a stick from underneath another
stick.
Input
The input consists of several test
cases. The first line of each test
case contains two integers n and m each at least one and no greater than one million. The integer n is
the number of sticks, and m is the number of lines that follow. The sticks are numbered from 1 to n.
Each of the following lines contains a pair of integers a, b, indicating that there is a point where stick a
lies on top of stick b. The last line of input is ‘0 0’. These zeros are not values of n and m, and should
not be processed as such.
Output
For each test case, output n lines of integers, listing the sticks in the order in which they could be
picked up without ever picking up a stick with another stick on top of it. If there are multiple such
correct orders, any one will do. If there is no such correct order, output a single line containing the
word ‘IMPOSSIBLE’.
Sample Input
3 2
1 2
2 3
0 0
Sample Output
1
2
3*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pr;
bool cycleExist(int sv,vector<bool> &recSt,vector<bool> &visited,vector<int> *adj_list) {
	visited[sv] = true;
	recSt[sv] = true;
	for(int x:adj_list[sv]){
		if(!visited[x] && cycleExist(x,recSt,visited,adj_list)){
			return true;
		}
		else if(recSt[x]){
			return true;
		}
	}
	recSt[sv] = false;
	return false;
}
void topoSort(vector<int> *adj_list,int n) {
	vector<int> indegree(n+1,0);
	for(int i=1;i<=n;i++){
		for(int x:adj_list[i]){
			indegree[x]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int vertex = q.front();
		q.pop();
		cout<<vertex<<"\n";
		for(int x:adj_list[vertex]){
			if(indegree[x]>0){
				indegree[x]--;
				if(indegree[x] == 0){
					q.push(x);
				} 
			}
		}
	}
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	while (cin >> n && cin >> m && n && m) {
		vector<int> *adj_list = new vector<int> [n + 1]();
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			adj_list[u].push_back(v);
		}
		bool cycle = false;
		vector<bool> visited(n+1,false);
		vector<bool> recSt(n+1,false);
		for(int i=1;i<=n && !cycle;i++){
			if(!visited[i]){
				cycle = cycleExist(i,recSt,visited,adj_list);
			}
		}
		if (cycle) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			topoSort(adj_list,n);
		}
		delete []adj_list;
	}
	return 0;
}