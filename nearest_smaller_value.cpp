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
	stack<int> st;
	for(int i=0;i<n;i++){
		while(!st.empty() && arr[i]<=arr[st.top()]){
			st.pop();
		}
		int ans = (st.empty()) ? 0 : st.top() + 1;
		cout<<ans<<" ";
		st.push(i);
	}
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