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
const int MOD = (1e9+7);
int power(int x,int y){
	int ans = 1LL;
	x %= MOD;
	while(y){
		if(y & 1){
			ans *= x;
			ans %= MOD;
		}
		x *= x;
		x %= MOD;
		y>>=1;
	}
	return ans;
}
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int lastIdx = (n+1)/2;
	int ans = 0;
	for(int i=0;i<lastIdx;i++){
		int rankLetter = s[i] - 'a';
		ans += (rankLetter * power(k,lastIdx-i-1));
		ans %= MOD;
	}
	string plusOne;
	for(int i=0;i<lastIdx;i++){
		plusOne.push_back(s[i]);
	}
	string temp = plusOne;
	if(s.length() % 2){
		temp.pop_back();
	}	
	reverse(temp.begin(),temp.end());
	plusOne += temp;
	if(plusOne < s){
		ans++;
		ans%=MOD;
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveQuestion();
	}
	return 0;
}