#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	int s = 0,maxm = 1;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		s += arr[i];
		maxm = max(maxm,arr[i]);
	}
	cout<<max(2*maxm,sum);
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