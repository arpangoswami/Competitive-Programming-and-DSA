#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	n++;
	int i=2;
	int ans = 0;
	while((n/i) > 0){
		ans += ((n/i) * (i/2));
		ans += ((n%i) > (i/2)) ? ((n%i) - (i/2)) : 0;
		i*=2;
	}
	ans += ((n%i) > (i/2)) ? ((n%i) - (i/2)) : 0;
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}