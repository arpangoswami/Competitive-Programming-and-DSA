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
	string s;
	cin >> s;
	int n = s.size();
	vector<bool> marked(n,false);
	vector<int> arr;
	for(int i=2;i<=(n-3);i++){
		if(s[i] == 'o' && s[i-1] == 'w' && s[i-2] == 't' && s[i+1] == 'n' && s[i+2] == 'e'){
			marked[i] = true;
			arr.push_back(i);
		}
	}
	for(int i=1;i<(n-1);i++){
		if(s[i] == 'n' && s[i-1] == 'o' && s[i+1] == 'e' && !marked[i] && !marked[i-1] && !marked[i+1]){
			arr.push_back(i);
		}else if(s[i] == 'w' && s[i-1] == 't' && s[i+1] == 'o' && !marked[i] && !marked[i-1] && !marked[i+1]){
			arr.push_back(i);
		}
	}
	cout<<arr.size()<<'\n';
	for(int x:arr){
		cout<<(x+1)<<" ";
	}
	cout<<'\n';
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