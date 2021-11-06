#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
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
vector<int> change(string &s,char ch1,char ch2,char ch3){
	int n = s.size();
	vector<int> sol(n);
	if(s[0] != ch1){
		sol[0]++;
	}
	for(int i=1;i<n;i++){
		sol[i] = sol[i-1];
		if(i % 3 == 0 && s[i] != ch1){
			sol[i]++;
		}else if(i % 3 == 1 && s[i] != ch2){
			sol[i]++;
		}else if(i % 3 == 2 && s[i] != ch3){
			sol[i]++;
		}
	}
	return sol;
}
void solveQuestion(){
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;
	//6 possibilities
	//abcabc...
	vector<int> pref1 = change(s,'a','b','c');
	//acbacb...
	vector<int> pref2 = change(s,'a','c','b');
	//bcabca...
	vector<int> pref3 = change(s,'b','c','a');
	//bacbac...
	vector<int> pref4 = change(s,'b','a','c');
	//cabcab...
	vector<int> pref5 = change(s,'c','a','b');
	//cbacba...
	vector<int> pref6 = change(s,'c','b','a');
	while(q--){
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		//do something
		int ans1 = pref1[y],ans2 = pref2[y],ans3 = pref3[y],ans4 = pref4[y],ans5 = pref5[y],ans6 = pref6[y];
		if(x > 0){
			ans1 -= pref1[x-1];
			ans2 -= pref2[x-1];
			ans3 -= pref3[x-1];
			ans4 -= pref4[x-1];
			ans5 -= pref5[x-1];
			ans6 -= pref6[x-1];
		}
		cout<<min({ans1,ans2,ans3,ans4,ans5,ans6})<<"\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}