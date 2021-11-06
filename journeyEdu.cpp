#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pii> pref(n+1);
	pref[0].first = 0;
	pref[0].second = 0;
	vector<pii> suff(n+1);
	suff[n].first = 0;
	suff[n].second = 0;
	for(int i=1;i<=n;i++){
		if(s[i-1] == 'R'){
			pref[i].second = 1 + pref[i-1].first;
			pref[i].first = 0;
		}else if(s[i-1] == 'L'){
			pref[i].second = 0;
			pref[i].first = 1 + pref[i-1].second;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(s[i] == 'R'){
			suff[i].first = 1 + suff[i+1].second;
			suff[i].second = 0;
		}else if(s[i] == 'L'){
			suff[i].first = 0;
			suff[i].second = 1 + suff[i+1].first;
		}
	}
	for(int i=0;i<=n;i++){
		cout<<1 + pref[i].first + suff[i].first<<" ";
	}
	cout<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}