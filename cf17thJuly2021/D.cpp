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
	int n;
	cin >> n;
	vi arr(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	vi sol(n+1);
	set<int> picked;
	set<int> notLiked;
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		mp[i] = 0;
	}
	for(int i=1;i<=n;i++){
		mp[arr[i]]++;
	}
	map<int,vector<int>> indices;
	for(int i=1;i<=n;i++){
		if(mp[arr[i]] >= 2){
			indices[arr[i]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(mp[i] == 0){
			notLiked.insert(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(picked.count(arr[i])){
			sol[i] = *notLiked.begin();
			notLiked.erase(sol[i]);
			if(sol[i] == i){
				swap(sol[i],sol[indices[arr[i]][0]]);
			}
		}else{
			picked.insert(arr[i]);
			sol[i] = arr[i];
		}
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(sol[i] == arr[i]){
			cnt++;
		}
	}
	cout<<cnt<<"\n";
	for(int i=1;i<=n;i++){
		cout<<sol[i]<<" ";
	}
	cout<<"\n";
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