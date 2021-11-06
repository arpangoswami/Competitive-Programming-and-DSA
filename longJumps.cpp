// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// typedef vector<int> vi;
// typedef pair<int,int> pii;
// int findParent(int x,vector<int> &parent){
// 	if(x == parent[x]){
// 		return x;
// 	}
// 	int val = findParent(parent[x],parent);
// 	parent[x] = val;
// 	return val;
// }
// void unionRank(int x,int y,vector<int> &parent,vector<int> &rank){
// 	int x_rep = findParent(x,parent),y_rep = findParent(y,parent);
// 	if(x_rep == y_rep){
// 		return;
// 	}
// 	if(rank[x_rep] > rank[y_rep]){
// 		parent[y_rep] = x_rep;
// 	}else if(rank[x_rep] < rank[y_rep]){
// 		parent[x_rep] = y_rep;
// 	}else{
// 		parent[y_rep] = x_rep;
// 		rank[x_rep]++;
// 	}
// }
// void solveQuestion(){
// 	int n;
// 	cin >> n;
// 	vi arr(n);
// 	vi parent(n);
// 	vi rank(n);
// 	for(int i=0;i<n;i++){
// 		parent[i] = i;
// 	}
// 	for(int i=0;i<n;i++){
// 		cin >> arr[i];
// 		if((i + arr[i]) < n){
// 			unionRank(i,i+arr[i],parent,rank);
// 		}
// 	}
// 	unordered_map<int,int> mp;
// 	for(int i=0;i<n;i++){
// 		mp[findParent(i,parent)] += arr[i];
// 	}
// 	int ans = 0;
// 	for(auto it:mp){
// 		ans = max(ans,it.second);
// 	}
// 	cout<<ans<<'\n';
// }
// int32_t main(int32_t argc,char const* argv[]){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(nullptr);
// 	//pre();
// 	int test;
// 	cin>>test;
// 	while(test--){
// 		solveQuestion();
// 	}
// 	return 0;
// }

#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<int> dp;
int n;
vi arr;
int solve(int i){
	if(i >= n){
		return 0;
	}
	if(dp[i] != -1){
		return dp[i];
	}
	int ans = arr[i] + solve(i+arr[i]);
	return dp[i] = ans;
}
void solveQuestion(){
	cin >> n;
	arr.resize(n);
	dp.resize(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		dp[i] = -1;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = max(ans,solve(i));
	}
	cout<<ans<<'\n';
	//cout<<maxScore<<'\n';
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