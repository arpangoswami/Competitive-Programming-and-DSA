#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n1,n2,n3;
	cin >> n1 >> n2 >> n3;
	int n = n1+n2+n3;
	vector<int> arr(n);
	int sum = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	int mini1 = 1e9,mini2 = 1e9,mini3 = 1e9,s1 = 0,s2 = 0,s3 = 0;
	for(int i=0;i<n1;i++){
		mini1 = min(mini1,arr[i]);
		s1 += arr[i];
	}
	for(int i=n1;i<(n1+n2);i++){
		mini2 = min(mini2,arr[i]);
		s2 += arr[i];
	}
	for(int i=(n1+n2);i<n;i++){
		mini3 = min(mini3,arr[i]);
		s3 += arr[i];
	}
	int mini = min({mini1+mini2,mini1+mini3,mini2+mini3});
	int ans = sum - 2*mini;
	ans = max(ans,sum - 2*min({s1,s2,s3}));
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}