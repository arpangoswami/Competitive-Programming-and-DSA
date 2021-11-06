#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n*k);
	for(int i=0;i<(n*k);i++){
		cin >> arr[i];
	}
	int ans = 0;
	int space = n/2;
	int cnt = 0;
	for(int i=(n*k) - space - 1;i>=0 && cnt < k;i-=(space+1)){
		ans += arr[i];
		cnt ++;
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