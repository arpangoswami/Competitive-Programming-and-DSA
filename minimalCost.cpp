#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool allEqual(vector<int> &arr,int n){
	int val = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i] != val){
			return false;
		}
	}
	return true;
}
bool allOneDiff(vector<int> &arr,int n){
	for(int i=1;i<n;i++){
		if(abs(arr[i] - arr[i-1]) > 1){
			return false;
		}
	}
	return true;
}
void solveQuestion(){
	int n,u,v;
	cin >> n >> u >> v;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	bool f = allEqual(arr,n);
	if(f){
		cout<<min(u,v) + v<<'\n';
		return;
	}
	f = allOneDiff(arr,n);
	if(f){
		cout<<min(u,v)<<'\n';
		return;
	}
	cout<<0<<'\n';
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