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
const int sz = 31;
vector<int> fact(sz);
void pre(){
	fact[0] = 1;
	for(int i=1;i<sz;i++){
		fact[i] = fact[i-1] * i;
	}
}
int simplify(int num,int a,int b){
	
}
string rank(int num,int a,int b){
	if(num == 1){
		string s;
		for(int i=0;i<a;i++){
			s.push_back('a');
		}
		for(int i=0;i<b;i++){
			s.push_back('b');
		}
		return s;
	}else if(a == 0){
		string s;
		for(int i=0;i<b;i++){
			s.push_back('b');
		}
		return s;
	}else if(b == 0){
		string s;
		for(int i=0;i<a;i++){
			s.push_back('a');
		}
		return s;
	}
	int aStart = simplify(a+b-1,a-1,b);
	if(num > aStart){
		return "a" + rank(num-aStart,a-1,b);
	}
	return "b" + rank(num,a,b-1);
}
void solveQuestion(){
	int a,b,k;
	cin >> a >> b >> k;
	cout << rank(k,a,b);
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

