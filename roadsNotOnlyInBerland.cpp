#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
int findParent(int x,vector<int> &parent){
	if(parent[x] == x){
		return x;
	}
	int par = findParent(parent[x],parent);
	parent[x] = par;
	return par;
}
void unionRank(int x,int y,vector<int> &parent,vector<int> &rank){
	int x_par = findParent(x,parent),y_par = findParent(y,parent);
	if(x_par == y_par){
		return;
	}
	if(rank[x_par] > rank[y_par]){
		parent[y_par] = x_par;
	}else if(rank[x_par] < rank[y_par]){
		parent[x_par] = y_par;
	}else{
		parent[y_par] = x_par;
		rank[x_par]++;
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> parent(n+1);
	vector<int> rank(n+1);
	for(int i=1;i<=n;i++){
		parent[i] = i;
	}
	vector<pii> arr;
	for(int i=1;i<n;i++){
		int x,y;
		cin >> x >> y;
		if(findParent(x,parent) == findParent(y,parent)){
			arr.push_back({x,y});
		}else{
			unionRank(x,y,parent,rank);
		}
	}
	int sz = arr.size();
	set<int> st;
	for(int i=1;i<=n;i++){
		st.insert(findParent(i,parent));
	}
	cout<<((int)st.size()-1)<<'\n';
	set<int>::iterator it = st.begin();
	int val1 = *it;
	it++;
	for(int i=0;i<sz && it!=st.end();it++,i++){
		//cout<<"yolo"<<'\n';
		cout<<arr[i].first<<" "<<arr[i].second<<" "<<val1<<" "<<(*it)<<'\n';
	}
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