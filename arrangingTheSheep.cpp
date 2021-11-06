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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> left(n,n*n);
	int ans = n*n,sheep = 0,sum = 0;
	for(int i=0;i<n;i++){
		if(s[i] == '*'){
			left[i] = sum;
			sheep++;
		}else{
			sum += sheep;
			left[i] = sum;
		}
	}
	sum = 0;
	sheep = 0;
	// for(int x:left){
	// 	cout<<x<<" ";
	// }
	// cout<<'\n';
	for(int i=n-1;i>=0;i--){
		if(s[i] == '*'){
			left[i] += sum;
			sheep++;
		}else{
			sum += sheep;
			left[i] += sum;
		}
	}
	// for(int x:left){
	// 	cout<<x<<" ";
	// }
	// cout<<'\n';
	cout << *min_element(left.begin(),left.end()) << '\n';
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