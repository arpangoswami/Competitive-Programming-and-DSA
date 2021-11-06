#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int n,m,k;
	cin >> n >> m >> k;
	int winHand = min(m,n/k);
	int losers = (m - winHand);
	//cout<<"losers: "<<losers<<'\n';
	int second = (losers + (k-2))/(k-1);
	cout<<winHand - second<<'\n';
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