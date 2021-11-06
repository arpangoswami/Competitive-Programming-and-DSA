/*
#include<bits/stdc++.h>
using namespace std;
struct cmpp
{
	bool operator()(pair<int,int> a,pair<int,int> b)
	{
		return a.second>b.second;
	}
};
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	vector< vector< pair<int,int> > > ed(n);
	while(m--)
	{
		int s,d,val;
		scanf("%d%d%d",&s,&d,&val);
		ed[s].push_back(pair<int,int>(d,val));
		ed[d].push_back(pair<int,int>(s,val));
	}
	while(q--)
	{
		int s1;
		scanf("%d",&s1);
		vector< bool > visit(n,false);
		priority_queue< pair<int,int> , vector< pair<int,int> > ,cmpp > pq;
		pq.push(pair<int,int>(s1,0));
		int r1=-1;
		int r2=-1;
		while(!pq.empty())
		{
			int s=pq.top().first;
			int len=pq.top().second;
			pq.pop();
			if(!visit[s])
			{
				visit[s]=true;
				bool end=true;
				for(int i=0;i<ed[s].size();i++)
				{
					int d=ed[s][i].first;
					int dis=ed[s][i].second;
					if(visit[d]==false)
					{
						pq.push(pair<int,int>(d,len+dis));
					}
				}
				if(end)
				{
					if(len==r1)
					{
						r2++;
					}
					else if(len>r1)
					{
						r1=len;
						r2=1;
					}
				}
			}
		}
		printf("%d %d",r1,r2);
		if(q!=0)
			printf("\n");
	}
	return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
typedef pair<int, pii> pr;
pii bfs(int sv, unordered_map<int, int> *adj_list) {
	unordered_map<int, ll> dist;
	unordered_set<int> visited;
	queue<pii> q;
	q.push({sv, 0});
	visited.insert(sv);
	while (!q.empty()) {
		pii temp = q.front();
		q.pop();
		ll par_dist = temp.second;
		int vertex = temp.first;
		for (auto it = adj_list[vertex].begin(); it != adj_list[vertex].end(); ++it) {
			int neighbour = it->first;
			int distance = it->second;
			if (!visited.count(neighbour)) {
				visited.insert(neighbour);
				q.push({neighbour, distance + par_dist});
				dist[neighbour] = distance + par_dist;
			}
		}
	}
	ll distance = 0;
	int cnt = 0;
	for (auto it = dist.begin(); it != dist.end(); ++it) {
		distance = max(distance, it->second);
	}
	for (auto it = dist.begin(); it != dist.end(); ++it) {
		if (it->second == distance) {
			cnt++;
		}
	}
	return {cnt, distance};
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	while (cin >> n >> m >> q && n && m && q) {
		unordered_map<int, int> *adj_list = new unordered_map<int, int>[n]();
		for (int i = 0; i < m; i++) {
			int u, v, len;
			cin >> u >> v >> len;
			if (u != v) {
				if (adj_list[u].count(v) == 0) {
					adj_list[u][v] = len;
					adj_list[v][u] = len;
				} else {
					int wt = adj_list[u][v];
					if (len < wt) {
						adj_list[u][v] = len;
						adj_list[v][u] = len;
					}
				}
			}
		}
		for (int i = 0; i < q; i++) {
			int sv;
			cin >> sv;
			pii ans = bfs(sv, adj_list);
			cout << ans.second << " " << ans.first;
			if(i!=q-1){
				cout<<"\n";
			}
		}
		delete []adj_list;
	}
	return 0;
}