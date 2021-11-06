#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	map<int,int> mp,mp2;
	int ans = n+1;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		mp[arr[i]]++;
		mp2[arr[i]] = i;
	}
	for(auto it:mp){
		if(it.second == 1){
			cout<<mp2[it.first] + 1<<'\n';
			return;
		}
	}
	cout<<-1<<'\n'; 
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