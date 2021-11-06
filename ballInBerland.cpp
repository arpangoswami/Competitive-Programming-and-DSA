#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int a,b,k;
	cin >> a >> b >> k;
	vi arr(k);
	unordered_map<int,int> mp;
	for(int &i:arr){
		cin >> i;
		mp[i]++;
	}
	unordered_map<int,int> mp2;
	vi arr2(k);
	for(int &i:arr2){
		cin >> i;
		mp2[i]++;
	}
	int ans = 0;
	for(int i=0;i<k;i++){
		ans += (k-(mp[arr[i]]-1)-(mp2[arr2[i]]-1)-1);
		//cout<<"ans: "<<ans<<'\n';
	}
	ans = max(ans,0LL);
	ans/=2;
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