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
	int a,b;
	cin >> a >> b;
	vi arr1(a-1);
	vi arr2(b-1);
	int s1 = 0,s2 = 0;
	for(int i=1;i<a;i++){
		arr1[i-1] = i;
		s1 += arr1[i-1];
	}
	for(int i=1;i<b;i++){
		arr2[i-1] = i;
		s2 += arr2[i-1];
	}
	if(a > b){
		int diff = (s1 - s2);
		cout << a << " ";
		cout << -(a + diff) << " ";
		for(int x:arr1){
			cout<<x<<" ";
		}
		for(int x:arr2){
			cout<<-x<<' ';
		}
	}else{
		int diff = (s2 - s1);
		cout << -b << " ";
		cout << (b + diff) << " ";
		for(int x:arr1){
			cout<<x<<" ";
		}
		for(int x:arr2){
			cout<<-x<<' ';
		}
	}
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