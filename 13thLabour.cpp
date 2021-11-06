#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	map<int,int> mp;
	vector<pii> weights(n);
	int sum = 0;
	for(int i=0;i<n;i++){
		cin >> weights[i].first;
		weights[i].second = i+1;
		sum += weights[i].first;
	}
	for(int i=0;i<(n-1);i++){
		int u,v;
		cin >> u >> v;
		mp[u]++;
		mp[v]++;
	}
	sort(weights.begin(),weights.end(),greater<pii>());
	vector<int> ans(n-1);
	ans[0] = sum;
	int i = 1,j = 0;
	while(i < (n-1)){
		ans[i] = ans[i-1];
		if(j < n){
			while(mp[weights[j].second] == 1){
				j++;
			}
			if(j < n){
				mp[weights[j].second]--;
				ans[i] += weights[j].first;
			}
		}
		i++;
	}
	for(int x:ans){
		cout<<x<<" ";
	}
	cout<<'\n';
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