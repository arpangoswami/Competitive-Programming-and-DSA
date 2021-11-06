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
/*
1
6
000001011110
111100100000
111111111111
*/
void bin(char c,string &s1,string &s2){
	int n = s1.size()/2;
	vector<int> v1,v2;
	for(int i=0;i<2*n;i++){
		if(s1[i] == c){
			v1.push_back(i);
		}
		if(s2[i] == c){
			v2.push_back(i);
		}
	}
	string ans;
	for(int i=0;i<v1[0];i++){
		ans.push_back(s1[i]);
	}
	for(int i=0;i<v2[0];i++){
		ans.push_back(s2[i]);
	}
	ans.push_back(c);
	for(int i=0;i<(n-1);i++){
		for(int j=v1[i]+1;j<v1[i+1];j++){
			ans.push_back(s1[j]);
		}
		for(int j=v2[i]+1;j<v2[i+1];j++){
			ans.push_back(s2[j]);
		}
		ans.push_back(c);
	}
	for(int i=v1[n-1]+1;i<2*n;i++){
		ans.push_back(s1[i]);
	}
	for(int i=v2[n-1]+1;i<2*n;i++){
		ans.push_back(s2[i]);
	}
	cout << ans << '\n';
}
void solveQuestion(){
	int n;
	cin >> n;
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	vector<string> s0,s1;
	for(int i=0;i<3;i++){
		int cnt[2] = {0};
		for(char c:s[i]){
			cnt[c-'0']++;
		}
		if(cnt[0] >= n){
			s0.push_back(s[i]);
		}else{
			s1.push_back(s[i]);
		}
	}
	if(s0.size() >= 2){
		bin('0',s0[0],s0[1]);
	}else if(s1.size() >= 2){
		bin('1',s1[0],s1[1]);
	}	
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