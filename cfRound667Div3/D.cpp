#include <bits/stdc++.h>
#include <cstdlib>
#define int unsigned long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
string modify(string &s,int i,int len){
	string toGive;
	for(int j=0;j<i;j++){
		toGive.push_back(s[j]);
	}
	toGive.push_back(s[i]+1);
	for(int j=i+1;j<len;j++){
		toGive.push_back('0');
	}
	return toGive;
}
void solveQuestion(){
	int n,sum;
	cin >> n >> sum;
	string s = to_string(n);
	int len = s.size();
	int sumFirst = 0;
	for(int i=0;i<len;i++){
		sumFirst += (s[i] - '0');
	}
	if(sumFirst <= sum){
		cout<<0<<"\n";
		return;
	}
	string poss = "1";
	for(int i=0;i<len;i++){
		poss.push_back('0');
	}
	int minDiff = stoull(poss) - n;
	int cumSum = 0;
	for(int i=0;i<len;i++){
		cumSum += (s[i]-'0');
		if(cumSum >= sum){
			break;
		}
		if(s[i] == '9'){
			continue;
		}
		poss = modify(s,i,len);
		minDiff = stoull(poss) - n;
	}
	cout<<minDiff<<"\n";
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