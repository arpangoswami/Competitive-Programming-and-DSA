#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	set<int> st;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		st.insert(x);
	}
	vector<int> arr(m);
	int ans = 0;
	for(int i=0;i<m;i++){
		cin >> arr[i];
		if(st.count(arr[i])){
			ans++;
		}
	}
	cout<<ans<<'\n';
	
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