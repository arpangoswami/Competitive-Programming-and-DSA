#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	set<int> absent;
	for(int i=0;i<=k;i++){
		absent.insert(i);
	}
	map<int,int> mp;
	for(int i=0;i<k;i++){
		mp[arr[i]]++;
		if(absent.count(arr[i])){
			absent.erase(arr[i]);
		}
	}
	vector<int> mex(n-k+1);
	int sz = n - k + 1;
	for(int i=k;i<n;i++){
		mex[i-k] = *(absent.begin());
		mp[arr[i]]++;
		if(mp[arr[i]] == 1){
			absent.erase(arr[i]);
		}
		mp[arr[i-k]]--;
		if(mp[arr[i-k]] == 0){
			absent.insert(arr[i-k]);
		}
	}
	mex[sz-1] = *(absent.begin());
	int ans = *min_element(mex.begin(),mex.end());
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}