#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	map<int,int> mp;
	for(int x:arr){
		mp[x]++;
	}
	int num = -1;
	for(auto it:mp){
		if(it.second == 1){
			num = it.first;
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(arr[i] == num){
			cout<<(i+1)<<"\n";
			return;
		}
	}
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