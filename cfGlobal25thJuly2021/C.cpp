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
	int n,k;
	cin >> n >> k;
	vector<pii> chords(k);
	set<int> st;
	for(int i=1;i<=2*n;i++){
		st.insert(i);
	}
	for(int i=0;i<k;i++){
		int x,y;
		cin >> x >> y;
		if(x > y){
			swap(x,y);
		}
		chords[i] = {x,y};
		st.erase(x);
		st.erase(y);
	}
	vector<int> remaining(2*(n-k));
	int ptr = 0;
	for(int x:st){
		remaining[ptr++] = x;
	}
	int N = remaining.size();
	for(int i=0;i<(N/2);i++){
		chords.push_back({remaining[i],remaining[i+(N/2)]});
	}
	sort(chords.begin(),chords.end());
	// for(pii x:chords){
	// 	cout<<x.ff<<" "<<x.ss<<"\n";
	// }
	int ans = 0;
	for(int i=0;i<(n-1);i++){
		for(int j=i+1;j<n;j++){
			if(chords[i].ss > chords[j].ff && chords[i].ss < chords[j].ss){
				ans++;
			}
		}
	}
	cout << ans << "\n";
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