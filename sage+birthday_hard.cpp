#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	vector<int> sol(n);
	int i = 1,idx1 = 0;
	for(;i<(n-1);i+=2){
		sol[i] = arr[idx1++];
	}
	i-=2;
	i++;
	int idx2 = n-1;
	for(;i>=0;i-=2){
		sol[i] = arr[idx2--];
	}
	if(idx1 == idx2){
		sol[n-1] = arr[idx1];
	}
	int cnt = 0;
	for(int i=1;i<(n-1);i++){
		if(sol[i] < sol[i-1] && sol[i] < sol[i+1]){
			cnt++;
		}
	}
	cout<<cnt<<"\n";
	for(int x:sol){
		cout<<x<<" ";
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