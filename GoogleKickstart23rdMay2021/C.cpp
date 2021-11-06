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
int average;
int points;
void solveQuestion(int win,int draw){
	cout<<"RS";
	for(int i=0;i<28;i++){
		cout<<"PS";
	}
	cout<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	average = 0;
	cin >> average;
	points = 0;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		int win,draw;
		cin >> win >> draw;
		solveQuestion(win,draw);
	}
	return 0;
}