#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<string, int> pii;
map<string,int> allPaths;
void solve(string &sv,string &dest,int cost,map<string,bool> &visited,map<string,vector<pii>> &adj_list,string path){
	if(sv == dest){
		allPaths[path] = cost;
		return;
	}
	visited[sv] = true;
	for(pii x:adj_list[sv]){
		string nb = x.first;
		int cst = x.second;
		if(!visited[nb]){
			solve(nb,dest,cost+cst,visited,adj_list,path + " " + nb);
		}
	}
	visited[sv] = false;
}
bool cmp(string &s1,string &s2){
	if(allPaths[s1] == allPaths[s2]){
		return s1.size() < s2.size();
	}
	return allPaths[s1] < allPaths[s2];
}
void solveQuestion(){
	string s;
	map<string,vector<pii>> adj_list;
	while(cin >> s){
		stringstream str(s);
		string word;
		vector<string> st;
		while(str >> word){
			cout<<word<<"\n";
			st.push_back(word);
		}
		for(string x:st){
			cout<<x<<" ";
		}
		cout<<"\n";
		adj_list[st[0]].push_back({st[1],0});
		// string src,dest;
		// int cst;
		// cin >> src >> dest >> cst;
		// adj_list[src].push_back({dest,cst});
	}
	map<string,bool> visited;
	for(auto it:adj_list){
		visited[it.first] = false;
	}
	string sv = "Entrance";
	string dest = "Vault";
	solve(sv,dest,0,visited,adj_list,"Entrance");
	vector<string> temp;
	for(auto it:allPaths){
		temp.push_back(it.first);
	}
	sort(temp.begin(),temp.end(),cmp);
	vector<string> sol;
	for(string x:temp){
		string t = x;
		t.push_back(' ');
		t += to_string(allPaths[x]);
		sol.push_back(t);
	}
	for(string x:sol){
		cout<<x<<"\n";
	}
}
int32_t main(int32_t argc, char const* argv[]) {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test = 1;
	//cin >> test;
	for (int t = 1; t <= test; ++t) {
		//cout << "Case #" << t << ": ";
		solveQuestion();
	}
	return 0;
}