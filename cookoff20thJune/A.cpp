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
	int n,q;
	cin >> n >> q;
	vi arr(n);
	set<int> roots;
	for(int &i:arr){
		cin >> i;
	}
	sort(arr.begin(),arr.end());
	for(int x:arr){
		roots.insert(x);
	}
	while(q--){
		int x;
		cin >> x;
		if(roots.count(x)){
			cout<<"0\n";
			continue;
		}
		if(n % 2){
			auto it = lower_bound(arr.begin(),arr.end(),x);
			if(it == arr.end()){
				cout<<"POSITIVE\n";
			}else{
				int pos = it - arr.begin();
				if(pos & 1){
					cout<<"POSITIVE\n";
				}else{
					cout<<"NEGATIVE\n";
				}
			}
		}else{
			auto it = lower_bound(arr.begin(),arr.end(),x);
			if(it == arr.end()){
				cout<<"POSITIVE\n";
			}else{
				int pos = it - arr.begin();
				if(pos & 1){
					cout<<"NEGATIVE\n";
				}else{
					cout<<"POSITIVE\n";
				}
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