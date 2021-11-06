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
int power(int a, int b){int res=1;a=a;while(b>0){if(b&1){res=(res*a);}a=(a*a);b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vi arr(n);
	for(int &x:arr){
		cin >> x;
	}
	set<int> powers;
	vector<vector<int>> required(n);
	for(int i=0;i<n;i++){
		int maxPower = 0,num = 1;
		while(num < arr[i]){
			num *= k;
			maxPower++;
		}
		num = arr[i];
		while(num > 0){
			int val = power(k,maxPower);
			if(val <= num){
				num -= val;
				required[i].push_back(maxPower);
			}
			maxPower--;
			if(maxPower < 0 && num > 0){
				cout<<"NO\n";
				return;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(arr[i] == 0){
			continue;
		}
		for(int x:required[i]){
			if(powers.count(x)){
				cout<<"NO\n";
				return;
			}
			powers.insert(x);
		}
	}
	cout << "YES\n";
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