#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,c0,c1,h;
	cin >> n >> c0 >> c1 >> h;
	string s;
	cin >> s;
	int freq[2] = {0};
	for(char c:s){
		freq[c - '0']++;
	}
	int ans = 1e9;
	for(int i=0;i<=n;i++){
		//i - no.of ones in the end;
		int cost = 0;
		if(i <= freq[1]){
			cost += (freq[1] - i)*h;
		}else{
			cost += (i - freq[1]) * h;
		}
		cost += i * c1 + (n-i)*c0;
		ans = min(ans,cost);
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