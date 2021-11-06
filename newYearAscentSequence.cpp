#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
bool check(vector<int> &arr){
	int minm = arr[0];
	for(int i=1;i<(int)arr.size();i++){
		if(minm < arr[i]){
			return true;
		}
		minm = min(minm,arr[i]);
	}
	return false;
}
void solveQuestion(){
	int n;
	cin >> n;
	int ans = 0;
	vector<pii> nonAscent;
	for(int i=0;i<n;i++){
		int len;
		cin >> len;
		vector<int> arr(len);
		for(int i=0;i<len;i++){
			cin >> arr[i];
		}
		if(!check(arr)){
			int maxm = *max_element(arr.begin(),arr.end());
			int minm = *min_element(arr.begin(),arr.end());
			nonAscent.push_back({maxm,minm});
		}
	}
	int N = nonAscent.size();
	sort(nonAscent.begin(),nonAscent.end());
	for(int i=0;i<N;i++){
		int val = nonAscent[i].second;
		pii temp = {val + 1,0};
		vector<pii> :: iterator it = lower_bound(nonAscent.begin(),nonAscent.end(),temp);
		int idx = it - nonAscent.begin();
		ans += (N-idx);
	}
	int rem = n - N;
	int add = 2*n - 1;
	for(int i=0;i<rem;i++){
		ans += add;
		add -= 2;
	}
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