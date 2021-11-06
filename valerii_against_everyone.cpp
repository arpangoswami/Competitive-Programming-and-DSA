#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	unordered_set<int> st;
	bool flag = false;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		if(st.count(x)){
			flag = true;
		}
		st.insert(x);
	}
	string ans = flag ? "YES" : "NO";
	cout<<ans<<"\n";
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