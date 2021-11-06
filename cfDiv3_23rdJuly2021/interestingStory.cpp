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
int solve(vector<string> &arr,int n,char letter){
	priority_queue<int> pq;
	for(string s:arr){
		int cntLet = 0,oth = 0;
		for(char c:s){
			if(c == letter){
				cntLet++;
			}else{
				oth++;
			}
		}
		pq.push(cntLet - oth);
	}
	int diff = 0,ans = 0;
	while(!pq.empty()){
		int x = pq.top();
		pq.pop();
		if(x > 0){
			ans++;
			diff += x;
		}else if(x <= 0){
			if(abs(x) < diff){
				ans++;
				diff += x;
			}else{
				return ans;
			}
		}
	}
	return ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<string> arr(n);
	for(string &s:arr){
		cin >> s;
	}
	int ans = solve(arr,n,'a');
	ans = max(ans,solve(arr,n,'b'));
	ans = max(ans,solve(arr,n,'c'));
	ans = max(ans,solve(arr,n,'d'));
	ans = max(ans,solve(arr,n,'e'));
	cout<<ans<<"\n";
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