#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,width;
	cin >> n >> width;
	multiset<int> mset;
	for(int i=0;i<n;i++){
		int v;
		cin >> v;
		mset.insert(v);
	}
	int ans = 1,available = width;
	while(!mset.empty()){
		auto it = mset.upper_bound(available);
		if(it == mset.begin()){
			ans++;
			available = width;
			continue;
		}
		--it;
		available -= *(it);
		mset.erase(it);
	}
	cout << ans << '\n';
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