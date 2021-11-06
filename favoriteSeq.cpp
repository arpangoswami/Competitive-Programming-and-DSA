#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	vector<int> sol(n);
	int i = 0,j = n-1,idx = 0;
	while(i < j){
		sol[idx++] = arr[i++];
		sol[idx++] = arr[j--];
	}
	if(i == j){
		sol[n-1] = arr[i];
	}
	for(int x:sol){
		cout<<x<<' ';
	}
	cout<<'\n';
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