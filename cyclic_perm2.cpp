#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<cstdlib>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds; 
//#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long ll;
typedef vector < ll > vl;
typedef vector < vl > vvl;
typedef pair < ll, ll > pll;
typedef long double ld;
typedef vector < pair < ll, ll > > vpll;
#define Boost() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define forn(i,n) for (ll i = 0; i < n; i++)
#define fo(i,n) for (ll i = 1; i <= n; i++)
#define fore(i,l,r) for (ll i = l; i <= r; i++)
#define rev(i,n) for(ll i=n-1;i>=0;i--)
#define all(c) c.begin(), c.end()
#define go(c,it) for(auto it=(c).begin(); it!=(c).end(); it++)
#define back(c,it) for(auto it=(c).rbegin(); it!=(c).rend(); it++)
#define fi first
#define se second
#define MOD 1000000007
ll power(ll a,ll b){ll res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
ll fact[500009];
ll fermat_inv(ll y){return power(y,MOD-2);}
ll nCrMod(ll n, ll r){ ll p=fact[n];ll q=(fact[r]*fact[n-r])%MOD;return (p*fermat_inv(q))%MOD;} 
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
const ld PI = acos(-1.0);
int main(){
	int test;
	cin>>test;
	while(test--){

	}
	return 0;
}