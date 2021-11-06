/*

There are N people on a street (numbered 1 through N).
 For simplicity, we'll view them as points on a line. For each valid ii, the position of the i-th person is Xi.

It turns out that exactly one of these people is infected with the virus COVID-19,
 but we do not know which one. The virus will spread from an infected person to a
  non-infected person whenever the distance between them is at most 2.
   If we wait long enough, a specific set of people (depending on the person that was infected initially) will become
    infected; let's call the size of this set the final number of infected people.

Your task is to find the smallest and largest value of the final number of infected people,
 i.e. this number in the best and in the worst possible scenario.  

*/
/*
3
1 2 3

5

*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int findParent(int node,unordered_map<int,int> &mp){
	if(node == mp[node]){
		return node;
	}
	int par = findParent(mp[node],mp);
	mp[node] = par;
	return par;
}
void unionRank(int x,int y,unordered_map<int,int> &parent,unordered_map<int,int> &ranks){
	int x_rep = findParent(x,parent),y_rep = findParent(y,parent);
	if(x_rep == y_rep){
		return;
	}
	if(ranks[x_rep] > ranks[y_rep]){
		parent[y_rep] = x_rep;
	}else if(ranks[x_rep] < ranks[y_rep]){
		parent[x_rep] = y_rep;
	}else{
		parent[x_rep] = y_rep;
		ranks[y_rep]++;
	}
}
//Time - O(n)
//Space - O(n)

void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	unordered_set<int> st;
	unordered_map<int,int> parent;
	unordered_map<int,int> ranks;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		st.insert(arr[i]);
		parent[arr[i]] = arr[i];
		ranks[arr[i]] = 1;
	}
	for(int i=0;i<n;i++){
		for(int j=-2;j<=2;j++){
			if(st.count(arr[i] + j)){
				unionRank(arr[i],arr[i]+j,parent,ranks);
			}
		}
	}
	unordered_map<int,int> mp;
	for(int x:arr){
		int par = findParent(x,parent);
		mp[par]++;
	}
	int maxm = INT_MIN,minm = INT_MAX;
	for(auto it:mp){
		maxm = max(maxm,it.second);
		minm = min(minm,it.second);
	}
	cout<<maxm<<" "<<minm<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}