#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using boost::multiprecision::cpp_int;
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
string id = "abcdefghijk"
void solveQuestion(int n){
	set<int>classes;
	for(int i=1;i<=100;i++){
		classes.insert(i);
	}
	map<string,string> identifier;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		stack<string> postfix;
		
	}	
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		int n;
		cin >> n;
		solveQuestion(n);
	}
	return 0;
}