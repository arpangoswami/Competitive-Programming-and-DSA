#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
void solveQuestion() {
	int n;
	cin >> n;
	vi arr(n);
	for (int &i : arr) {
		cin >> i;
	}
	map<int,vector<int>> mpSame;
	for(int i=0;i<n;i++){
		mpSame[arr[i]].push_back(i);
		if(mpSame[arr[i]].size() >= 4){
			cout<<"YES"<<'\n';
			cout<<mpSame[arr[i]][0]+1<<" "<<mpSame[arr[i]][1] + 1<<" "<<mpSame[arr[i]][2] + 1<<" "<<mpSame[arr[i]][3] + 1<<'\n';
			return;
		}
	}
	map<int, vector<pii>> mp;
	for (int i = 0; i < (n - 1); i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = arr[i] + arr[j];
			if (mp.count(sum)) {
				for(pii temp:mp[sum]){
					int x = temp.first,y = temp.second;
					if( (x != i && x != j) && (y != i && y != j)){
						cout<<"YES"<<'\n';
						cout<<x+1<<" "<<y+1<<" "<<i+1<<" "<<j+1<<'\n';
						return;
					}
				}
			}
			mp[sum].push_back({i,j});
		}
	}
	cout<<"NO"<<'\n';
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}