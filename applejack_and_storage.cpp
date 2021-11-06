#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
void solveQuestion(){
	int n;
	cin >> n;
	int cnt2 = 0,cnt4 = 0;
	vector<int> arr(1e5+1);
	for(int i=0;i<n;i++){
		int val;
		cin >> val;
		cnt2 -= arr[val]/2;
		cnt4 -= arr[val]/4;
		arr[val]++;
		cnt2 += arr[val]/2;
		cnt4 += arr[val]/4;
	}
	int q;
	cin >> q;
	while(q--){
		char c;
		int val;
		cin >> c >> val;
		cnt2 -= (arr[val])/2;
		cnt4 -= (arr[val])/4;
		if(c == '+'){
			arr[val]++;
		}else{
			arr[val]--;
		}
		cnt2 += (arr[val])/2;
		cnt4 += (arr[val])/4;
		if(cnt2 >=4 && cnt4 >= 1){
			cout<<"YES"<<'\n';
		}else{
			cout<<"NO"<<'\n';
		}
	}

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