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
	int n,c;
	cin >> n >> c;
	int ans = 0;
	vector<int> prefSum(10001);
	for(int i=0;i<n;i++){
		int l,r;
		cin >> l >> r;
		if((r-l) == 0){
			continue;
		}
		ans++;
		if((r-l) == 1){
			continue;
		}
		prefSum[l+1]++;
		prefSum[r]--;
	}
	//cout<<ans<<"\n";
	for(int i=1;i<=10000;i++){
		prefSum[i] += prefSum[i-1];
	}
	priority_queue<pii> pq;
	for(int i=0;i<=10000;i++){
		if(prefSum[i] > 0){
			pq.push({prefSum[i],i});
		}
	}
	// priority_queue<pii> temp;
	// while(!pq.empty()){
	// 	cout<<pq.top().second<<" "<<pq.top().first<<"\n";
	// 	temp.push(pq.top());
	// 	pq.pop();
	// }
	// temp.swap(pq);
	for(int i=0;i<c && !pq.empty();i++){
		pii temp = pq.top();
		pq.pop();
		ans += temp.first;
	}
	cout<<ans<<"\n";
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