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
	int ans = 0;
	for(int i=0;i<(n-1);i++){
		if(s[i] == s[i+1]){
			ans++;
		}
	}
	cout<<(ans+1)/2<<"\n";
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