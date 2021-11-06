#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
const int MX = 2e5;
typedef array<int,4> ar;
void solveQuestion(){
	int n;
	cin >> n;
	vector<ar> v(n);
	vector<int> x_co;
	vector<int> y_co;
	for(int i=0;i<n;i++){
		cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
		x_co.push_back(v[i][0]);
		x_co.push_back(v[i][2]);
		y_co.push_back(v[i][1]);
		y_co.push_back(v[i][3]);
	}
	sort(x_co.begin(),x_co.end());
	sort(y_co.begin(),y_co.end());
	int N = x_co.size();
	cout<<x_co[(N - 1)/2]<<" "<<y_co[(N - 1)/2]<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}