#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
unordered_map<int,int> primefactors(int n){
	unordered_map<int,int> ans;
	while(n%2 == 0){
		ans[2]++;
		n/=2;
	}
	for(int i=3;i*i<=n;i+=2){
		while(n % i == 0){
			ans[i]++;
			n/=i;
		}
	}
	if(n > 2){
		ans[n]++;
	}
	return ans;
}
void solveQuestion(){
	int x,y;
	cin >> x >> y;
	if(x % y != 0){
		cout<<x<<"\n";
		return;
	}
	unordered_map<int,int> fact = primefactors(y);
	int ans = 1;
	for(auto it:fact){
		int temp = x;
		int factor = it.first;
		while(temp % y == 0){
			temp/=factor;
		}
		ans = max(ans,temp);
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