#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	int sum = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	if(sum % 3 != 0){
		cout<<0<<'\n';
		return;
	}
	int first = sum/3,second = 2*first,fs = 0,ans = 0,curr = arr[0];
	for(int i=1;i<(n-1);i++){
		curr += arr[i];
		if(curr == first){
			fs++;
		}
		if(curr == second){
			ans += fs;
		}
		//cout<<"i: "<<i<<" ans: "<<ans<<'\n';
	}
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