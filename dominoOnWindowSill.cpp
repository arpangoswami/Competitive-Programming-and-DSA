#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
void solveQuestion(){
	int n,k1,k2,w,b;
	cin >> n >> k1 >> k2 >> w >> b;
	int white = min(k1,k2) + (max(k1,k2) - min(k1,k2))/2;
	int K1 = n-k1,K2 = n-k2;
	int black = min(K1,K2) + (max(K1,K2) - min(K1,K2))/2;
	if(white >= w && black >= b){
		cout<<"YES"<<'\n';
		return;
	}
	cout<<"NO"<<'\n';
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