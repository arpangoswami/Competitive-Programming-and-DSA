#include <bits/stdc++.h>
#define int long long
using namespace std;
char findParent(char ch,unordered_map<char,char> &parent){
	if(ch == parent[ch]){
		return ch;
	}
	char c = findParent(parent[ch],parent);
	parent[ch] = c;
	return c;
}
void unionRank(char x,char y,unordered_map<char,char> &parent,unordered_map<char,int> &rank){
	char x_rep = findParent(x,parent),y_rep = findParent(y,parent);
	if(x_rep == y_rep){
		return;
	}
	if(rank[x_rep] > rank[y_rep]){
		parent[y_rep] = x_rep;
	}else if(rank[y_rep] > rank[x_rep]){
		parent[x_rep] = y_rep;
	}else{
		parent[x_rep] = y_rep;
		rank[y_rep]++;
	}
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		unordered_map<char,char> parent;
		unordered_map<char,int> rank;
		for(int i=0;i<20;i++){
			parent['a' + i] = 'a' + i;
			rank['a' + i] = 1;
		}
		int steps = 0;
		for(int i=0;i<n;i++){
			if(s[i] > t[i]){
				steps = -1;
				break;
			}else{
				if(findParent(s[i],parent) != findParent(t[i],parent)){
					unionRank(s[i],t[i],parent,rank);
					steps++;
				}
			}
		}
		cout << steps << "\n";
	}
	return 0;
}