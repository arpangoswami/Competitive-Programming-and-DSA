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
void solveQuestion(){
	int a,b;
	cin >> a >> b;
	string s;
	cin >> s;
	int oneCnt = count(s.begin(),s.end(),'1');
	if(oneCnt == 0){
		cout<<"0\n";
		return;
	}
	int n = s.size();
	vpi intervals;
	int ans = a;
	char prev = '0';
	for(int i=0;i<n;){
		if(s[i] == '0'){
			i++;
			continue;
		}
		int start = i;
		while(i < n && s[i] == '1'){
			i++;
		}
		intervals.push_back({start,i-1});
	}
	for(int i=1;i<(int)intervals.size();i++){
		int zerosBtw = intervals[i].ff - intervals[i-1].ss - 1;
		if(zerosBtw * b < a){
			ans += zerosBtw * b;
		}else{
			ans += a;
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