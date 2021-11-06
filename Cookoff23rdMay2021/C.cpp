#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int x,y;
	cin >> x >> y;
	if(y % x != 0){
		cout<<"-1\n";
		return;
	}
	if(x == y){
		cout<<"1\n";
		return;
	}
	int temp = x;
	int add = 2*x;
	map<int,int> days;
	int d = 1;
	set<int> st;
	while(temp <= y){
		st.insert(temp);
		days[temp] = d;
		temp += add;
		add *= 2LL; 
		d++;
	}
	st.insert(temp);
	days[temp] = d;
	int ans = 0;
	while(y > 0){
		if(st.empty()){	
			cout<<"-1\n";
			return;
		}
		auto it = st.lower_bound(y);
		if(it == st.end()){
			cout<<"-1\n";
			return;
		}
		if((*it) == y){
			ans += days[(*it)];
			y -= (*it);
		}else{
			if(it == st.begin()){
				cout<<"-1\n";
				return;
			}
			--it;
			y -= (*it);
			ans += days[(*it)];
			ans++;
			st.erase(it);
		}
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}