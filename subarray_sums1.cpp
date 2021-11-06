#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,sum;
	cin >> n >> sum;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int curr_sum = 0;
	int j = 0;
	int ans = 0;
	for(int i=0;i<n;i++){
		curr_sum += arr[i];
		while(curr_sum > sum){
			curr_sum -= arr[j];
			j++;
		}
		if(curr_sum == sum){
			ans++;
		}
	}
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