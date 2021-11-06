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
string s,t;
int n1,n2;
bool solve(int idx1,int idx2,bool left,bool right){
	//cout<<"s[idx1]: "<<s[idx1]<<" idx1: "<<idx1<<"\n";
	if(idx2 == n2){
		return true;
	}
	bool ans = false;
	if(idx1 > 0 && s[idx1-1] == t[idx2] && (left || right)){
		ans |= solve(idx1-1,idx2+1,true,false);
	}
	if(idx1 < (n1-1) && s[idx1+1] == t[idx2] && !left){
		ans |= solve(idx1+1,idx2+1,false,true);
	}
	return ans;
}
void solveQuestion(){
	cin >> s >> t;
	n1 = s.size();
	n2 = t.size();
	for(int i=0;i<n1;i++){
		if(s[i] == t[0]){
			//true -> right
			//left -> false
			bool f = solve(i,1,false,true);
			if(f){
				cout<<"YES\n";
				return;
			}
		}
	}
	cout<<"NO\n";
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