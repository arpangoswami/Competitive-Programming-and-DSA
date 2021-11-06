#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	vi arr(n);
	vi cost(m);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for(int i=0;i<m;i++){
		cin >> cost[i];
	}
	sort(arr.begin(),arr.end(),greater<int>());
	int remIdx = 0;
	int ans = 0;
	for(int i=0;i<n;i++){
		if(remIdx == m){
			ans += cost[arr[i]-1];
		}
		int direct = cost[arr[i]-1],gift = cost[remIdx];
		if(direct <= gift){
			ans+=direct;
		}else{
			ans += gift;
			remIdx++;
		}
	}
	cout<<ans<<'\n';
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