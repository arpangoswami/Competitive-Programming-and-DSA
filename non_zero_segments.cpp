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
	unordered_set<int> st;
	st.insert(0);
	int ans = 0;
	int sum = 0;
	for(int x:arr){
		sum += x;
		if(st.count(sum)){
			ans++;
			sum = x;
			st.clear();
			st.insert(0);
		}
		st.insert(sum);
	}
	cout<<ans<<"\n";
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