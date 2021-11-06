#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	string s,t;
	cin >> s >> t;
	vector<int> left(m),right(m);
	int idx = 0;
	for(int i=0;i<n && idx < m;i++){
		if(s[i] == t[idx]){
			left[idx] = i;
			idx++;
		}
	}
	idx = m-1;
	for(int i=n-1;i>=0 && idx >=0;i--){
		if(s[i] == t[idx]){
			right[idx] = i;
			idx--;
		}
	}
	int ans = 1;
	for(int i=1;i<m;i++){
		ans = max(ans,right[i] - left[i-1]);
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