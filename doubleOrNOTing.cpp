#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAX_LIMIT = 1e9;
int NOTnum(int n){
	if(n == 0){
		return 1LL;
	}
	bool f = false;
	int ans = 0;
	for(int i=9;i>=0;i--){
		if(((n >> i) & 1) == 0){
			if(f){
				ans += (1 << i);
			}
		}else{
			f = true;
		}
	}
	return ans;
}
int bfs(int start,int end){
	vector<int> distance(513,MAX_LIMIT);
	vector<int> visited(513,false);
	queue<int> q;
	q.push(start);
	visited[start] = true;
	distance[start] = 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		if(v == end){
			return distance[v];
		}
		int n1 = 2*v,n2 = NOTnum(v);
		if(n1 <= 512 && visited[n1] == false){
			q.push(n1);
			visited[n1] = true;
			distance[n1] = 1 + distance[v];
			//cout<<"here "<<n1<<" "<<1 + distance[v]<<'\n';
		}
		if(n2 <= 512 && visited[n2] == false){
			q.push(n2);
			visited[n2] = true;
			distance[n2] = 1 + distance[v];
			//cout<<"here "<<n2<<" "<<1 + distance[v]<<'\n';
		}
	}
	return MAX_LIMIT;
}
void solveQuestion(){
	string strt,en;
	cin >> strt >> en;
	int start = stoi(strt, nullptr, 2);
	int end = stoi(en, nullptr, 2);
	int ans = bfs(start,end);
	if(ans >= MAX_LIMIT){
		cout<<"IMPOSSIBLE"<<'\n';
		return;
	}
	cout << ans << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveQuestion();
	}
	return 0;
}