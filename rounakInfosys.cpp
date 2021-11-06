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
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
typedef array<int,3> ar;


typedef long long ll;
class BIT{
	vector<ll> fenwick;
	int n;
public:
	BIT(int _n){
		n = _n+1;
		fenwick.assign(n,0);
	}
	BIT(vector<int> arr):BIT(arr.size()){
		for (size_t i = 0; i < arr.size(); i++)
            update(i+1, arr[i]);
	}
	void update(int idx,int delta){
		for(;idx<n;idx += (idx & (-idx))){
			fenwick[idx] += delta;
		}
	}
	ll ans(int idx){
		ll ans = 0;
		for(;idx>0;idx -= (idx & (-idx))){
			ans += fenwick[idx];
		}
		return ans;
	}
	ll ansRange(int left,int right){
		return ans(right) - ans(left-1);
	}
};
int solve(int N,int Q,vector<ll> arr,vector<int> type,vector<int> L,vector<int> R){
	set<int> evenIndices;
	set<int> oddIndices;
	set<int> ones;
	ll prevSum = 0;
	for(int i=1;i<=N;i++){
		if(arr[i] == 1){
			ones.insert(i);
		}
		else if(arr[i] % 2 == 0){
			evenIndices.insert(i);
		}else{
			oddIndices.insert(i);
		}
		prevSum += arr[i];
	}
	ll sum = 0;
	BIT bit(arr);
	for(int i=0;i<Q;i++){
		int q = type[i];
		int left = L[i],right = R[i];
		if(q == 1){
			int l = left-1,r = right-1;
			vector<ll> evenToErase;
			auto it1 = evenIndices.lower_bound(l);
			auto it2 = evenIndices.upper_bound(r);
			for(auto it=it1;it!=it2;it++){
				int idx = *it;
				int newVal = arr[idx] | (arr[idx] - 1);
				bit.update(idx+1,newVal - arr[idx]);
				arr[idx] = newVal;
				evenToErase.push_back(idx);
				if((newVal&1)&&(newVal > 1)){
					oddIndices.insert(idx);
				}else{
					ones.insert(idx);
				}
			}
			for(int x:evenToErase){
				evenIndices.erase(x);
			}
		}else if(q == 2){
			int l = left-1,r = right-1;
			vector<ll> evenToErase;
			vector<ll> oddToErase;
			auto it1 = evenIndices.lower_bound(l);
			auto it2 = evenIndices.upper_bound(r);
			vector<ll> oddToInsert;
			for(auto it=it1;it!=it2;it++){
				int idx = *it;
				int newVal = arr[idx] ^ (arr[idx] - 1);
				bit.update(idx+1,newVal - arr[idx]);
				arr[idx] = newVal;
				evenToErase.push_back(idx);
				if((newVal&1)&&(newVal > 1)){
					oddToInsert.push_back(idx);
				}else{
					ones.insert(idx);
				}
			}
			it1 = oddIndices.lower_bound(l);
			it2 = oddIndices.upper_bound(r);
			for(auto it=it1;it!=it2;it++){
				int idx = *it;
				int newVal = arr[idx] ^ (arr[idx] - 1);
				bit.update(idx+1,newVal - arr[idx]);
				arr[idx] = newVal;
				oddToErase.push_back(idx);
				ones.insert(idx);
			}
			for(int x:oddToInsert){
				oddIndices.insert(x);
			}
			for(int x:evenToErase){
				evenIndices.erase(x);
			}
			for(int x:oddToErase){
				oddIndices.erase(x);
			}
		}
		sum += bit.ansRange(1,N);
	}
	return (sum % MOD);
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	cout << solve(4,2,{5,4,8,6},{1,2},{1,2},{3,2}) << "\n";
	return 0;
}