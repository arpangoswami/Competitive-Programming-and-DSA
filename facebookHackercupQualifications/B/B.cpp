#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
const int INF = 1e5;
vector<int> modifyDist(int v,vector<int> edges[]){
	vector<int> dist(26,10*INF);
	queue<int> q;
	bitset<26> bset;
	bset[v] = 1;
	dist[v] = 0;
	q.push(v);
	while(!q.empty()){
		int vert = q.front();
		q.pop();
		for(int x:edges[vert]){
			if(!bset[x]){
				q.push(x);
				dist[x] = 1 + dist[vert];
				bset[x] = 1;
			}
		}
	}
	return dist;
}
void solveQuestion(){
	string s;
	cin >> s;
	int N = s.size();
	vector<int> arr(N);
	vector<int> freq(26);
	vector<vector<int>> dist(26,vector<int>(26,1e6));
	for(int i=0;i<26;i++){
		dist[i][i] = 0;
	}
	for(int i=0;i<N;i++){
		arr[i] = s[i] - 'A';
		freq[arr[i]]++;
	}
	int k;
	cin >> k;
	vector<int> edges[26];
	for(int i=0;i<k;i++){
		string edge;
		cin >> edge;
		int v1 = edge[0] - 'A',v2 = edge[1] - 'A';
		edges[v2].push_back(v1);
	}
	for(int i=0;i<26;i++){
		dist[i] = modifyDist(i,edges);
	}
	int ans = 1e6;
	for(int ch = 0;ch < 26;ch++){
		int sum = 0;
		for(int j=0;j<26;j++){
			sum += dist[ch][j] * freq[j];
		}
		ans = min(ans,sum);
	}
	if(ans > INF){
		ans = -1;
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	#ifndef ONLINE_JUDGE

	freopen("B_input.txt", "r", stdin);

	freopen("B_output.txt", "w", stdout);

	#endif // ONLINE_JUDGE

	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}