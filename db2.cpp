/*
3
12
zeffshwenhid
10
flyaxqozsq
15
xmdezmcwakuttit

423076930
418181825
891666678
*/
#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
const int MOD = 1e9 + 7;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
int sumDiffChars(vector<int> pos[],int N){
	int sum = 0;
	for(int i=0;i<26;i++){
		for(int j=1;j<pos[i].size();j++){
			int add = (pos[i][j] - pos[i][j-1])*(N-pos[i][j]);
			add %= MOD;
			sum += add;
			sum %= MOD;
		}
	}
	return sum;
}
void solveQuestion(){
	int N;
	cin >> N;
	string s;
	cin >> s;
	vector<int> pos[26];
	for(auto &x:pos){
		x.push_back(-1);
	}
	for(int i=0;i<N;i++){
		int idx = s[i] - 'a';
		pos[idx].push_back(i);
	}
	int sum = sumDiffChars(pos,N);
	int den = (N*(N+1))/2;
	int g = gcd(sum,den);
	sum /= g;
	den /= g;
	cout<< (sum * fermat_inv(den))%MOD << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}