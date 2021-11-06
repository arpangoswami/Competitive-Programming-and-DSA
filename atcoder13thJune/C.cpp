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
void solveQuestion(){
	int a,b,c;
	cin >> a >> b >> c;
	if(a == b){
		cout<<"=";
	}else if(((c % 2) + 2)%2 == 0 && abs(a) == abs(b)){
		cout<<"=";
	}else if(a == 0){
		if(b > 0 || ((c % 2)+2)%2 == 0){
			cout<<"<";
		}else{
			cout<<">";
		}
	}else if(b == 0){
		if(a > 0 || ((c % 2)+2)%2 == 0){
			cout<<">";
		}else{
			cout<<"<";
		}
	}else if(c == 0){
		if(a > b){
			cout<<">";
		}else{
			cout<<"<";
		}
	}else if(a > 0 && b > 0){
		if(a > b){
			string ans = (c > 0) ? ">" : "<";
			cout<<ans;
		}else{
			string ans = (c > 0) ? "<" : ">";
			cout<<ans;
		}
	}else if(a > 0 && b < 0){
		if(((c % 2)+2)%2 == 0){
			if(a > abs(b)){
				string ans = (c > 0) ? ">" : "<";
				cout<<ans;
			}else{
				string ans = (c > 0) ? "<" : ">";
				cout<<ans;
			}
		}else{
			cout<<">";
		}
	}else if(a < 0 && b > 0){
		if(((c % 2)+2)%2 == 0){
			if(abs(a) > b){
				string ans = (c > 0) ? ">" : "<";
				cout<<ans;
			}else{
				string ans = (c > 0) ? "<" : ">";
				cout<<ans;
			}
		}else{
			cout<<"<";
		}
	}else if(a < 0 && b < 0){
		if(((c % 2)+2)%2 == 0){
			if(abs(a) > abs(b)){
				string ans = (c > 0) ? ">" : "<";
				cout<<ans;
			}else{
				string ans = (c > 0) ? "<" : ">";
				cout<<ans;
			}
		}else{
			if(a > b){
				string ans = (c > 0) ?  ">" : "<";
				cout<<ans;
			}else{
				string ans = (c > 0) ? "<" : ">";
				cout<<ans;
			}
		}
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