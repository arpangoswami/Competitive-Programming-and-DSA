#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int n;
	cin >> n;
	unordered_map<int,int> st;
	int val = 3LL;
	int cnt = 1LL;
	while(val < n){
		st[val] = cnt;
		val *= 3LL;
		cnt++;
	}
	val = 5LL;
	cnt = 1LL;
	unordered_map<int,int> st2;
	while(val < n){
		st2[val] = cnt;
		val *= 5LL;
		cnt++;
	}
	for(auto it:st){
		if(st2.count(n-it.first)){
			cout<<it.second<<" "<<st2[n-it.first]<<'\n';
			return;
		}
	}
	cout<<-1<<'\n';
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