#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	int low = 1,high = n,ans = 1;
	while(low <= high){
		int mid = (low + high)/2;
		int large = ((mid * mid) + 1)/2;
		if(large <= n){
			ans = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	if(ans % 2 == 0){
		ans--;
	}
	cout<<(ans/2)<<'\n';
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