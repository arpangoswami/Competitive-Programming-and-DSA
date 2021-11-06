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
void solveQuestion(){
	int n;
	cin >> n;
	vi original(n);
	for(int &x:original){
		cin >> x;
	}
	vi modify(n-1);
	for(int &x:modify){
		cin >> x;
	}
	sort(original.begin(),original.end());
	sort(modify.begin(),modify.end());
	vector<int> pref(n);
	vector<int> suff(n);
	for(int i=0;i<(n-1);i++){
		pref[i] = modify[i] - original[i];
	}
	for(int i=1;i<n;i++){
		suff[i] = modify[i-1] - original[i];
	}
	vector<bool> prefCorr(n);
	vector<bool> suffCorr(n);
	int ans = 1e10;
	prefCorr[0] = true;
	suffCorr[n-1] = modify[n-2] > original[n-1];
	for(int i=1;i<n;i++){
		if(pref[i] == pref[i-1]){
			prefCorr[i] = prefCorr[i-1];
		}
	}
	for(int i=n-2;i>=0;i--){
		if(suff[i] == suff[i+1]){
			suffCorr[i] = suffCorr[i+1];
		}
	}
	for(int i=0;i<n;i++){
		if(i == 0){
			if(suffCorr[i+1]){
				ans = min(ans,suff[i+1]);
			}
		}else if(i == n-1){
			if(prefCorr[i-1]){
				ans = min(ans,pref[i-1]);
			}
		}else{
			if(prefCorr[i-1] && suffCorr[i+1] && pref[i-1] == suff[i+1]){
				ans = min(ans,pref[i-1]);
			}
		}
	}
	cout<<ans<<"\n";
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