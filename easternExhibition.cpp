#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr1(n),arr2(n);
	for(int i=0;i<n;i++){
		cin >> arr1[i] >> arr2[i];
	}
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
	cout<<(arr1[n/2] - arr1[(n-1)/2] + 1)*(arr2[n/2] - arr2[(n-1)/2] + 1)<<'\n';
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