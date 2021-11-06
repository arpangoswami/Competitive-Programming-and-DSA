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
	map<int,int> mp;
	map<int,int> curr;
	curr[0] = 1;
	for(int x:arr){
		map<int,int> mp2;
		for(auto y:curr){
			mp2[y.first | x] += curr[y.first];
		}
		mp2[x]++;
		curr = mp2;
		for(auto x:curr){
			mp[x.first] += curr[x.first];
		}
	}
	int s = 0;
	for(auto x:mp){
		cout<<x.first<<" "<<x.second<<"\n";
		s += (x.first) * (x.second);
	}
	cout<<s<<"\n";
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