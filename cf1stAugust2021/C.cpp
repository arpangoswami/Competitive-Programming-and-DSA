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
	int n,m;
	cin >> n >> m;
	int deaths = 0;
	vector<int> weakerTo(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		if(u > v){
			swap(u,v);
		}
		weakerTo[u]++;
		if(weakerTo[u] == 1){
			//will die some time later
			// having check == 1 as we do not want to count one noble more than once
			deaths++;
		}
	}
	int q;
	cin >> q;
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int u,v;
			cin >> u >> v;
			if(u > v){
				swap(u,v);
			}
			weakerTo[u]++;
			if(weakerTo[u] == 1){
				//will die some time later
				// having check == 1 as we do not want to count one noble more than once
				deaths++;
			}
		}else if(type == 2){
			int u,v;
			cin >> u >> v;
			if(u > v){
				swap(u,v);
			}
			weakerTo[u]--;
			if(weakerTo[u] == 0){
				//will not die now as no stronger friends exist
				// having check == 0 as we do not want to count one noble more than once
				deaths--;
			}
		}else{
			cout << (n - deaths) << "\n";
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