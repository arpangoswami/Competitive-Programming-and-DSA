#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	vi sol(n);
	map<int,int> mp;
	stack<int> st;
	for(int i=0;i<n;i++){
		while(!st.empty() && st.top() < arr[i]){
			int val = st.top();
			mp[val]--;
			st.pop();
		}
		sol[i] = mp[arr[i]];
		mp[arr[i]]++;
		st.push(arr[i]);
	}
	while(!st.empty()){
		st.pop();
	}
	mp.clear();
	for(int i=n-1;i>=0;i--){
		while(!st.empty() && st.top() < arr[i]){
			int val = st.top();
			mp[val]--;
			st.pop();
		}
		sol[i] += mp[arr[i]];
		mp[arr[i]]++;
		st.push(arr[i]);
	}
	for(int x:sol){
		cout << x << " ";
	}
	cout << '\n';

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