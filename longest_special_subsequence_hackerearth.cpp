#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,k;
	string s;
	cin >> n >> k >> s;
	vector<int> freq_appeared(26,0);
	for(int i=0;i<n;i++){
		int ans = 1;
		int lower = s[i] - 'a' - k;
		lower = max(lower,0LL);
		int higher = s[i] - 'a' + k;
		higher = min(higher,25LL);
		for(int j=lower;j<=higher;j++){
			if(1 + freq_appeared[j] > ans){
				ans = 1 + freq_appeared[j];
			}
		}
		freq_appeared[s[i] - 'a'] = ans;
	}
	int ans = 1;
	for(int x:freq_appeared){
		ans = max(x,ans);
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}