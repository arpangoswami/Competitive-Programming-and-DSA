#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	map<int,vector<int>> mp;
	for(int i=0;i<n;i++){
		mp[arr[i]].push_back(i);
	}
	int ops = n+1;
	for(auto it:mp){
		vector<int> pos = it.second;
		int curr = 0;
		int sz = pos.size();
		int prevIndex = -1;
		for(int i=0;i<sz;i++){
			if(i == sz-1 && pos[i]!=n-1){
				curr++;
			}
			if(pos[i]!=prevIndex+1){
				curr++;
			}
			prevIndex = pos[i];
		}
		ops = min(curr,ops);
	}
	cout<<ops<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}