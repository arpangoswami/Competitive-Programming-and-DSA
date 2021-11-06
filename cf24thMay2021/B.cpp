#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
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
	if(n == 1){
		cout<<"1\n";
		return;
	}
	sort(arr.begin(),arr.end());
	if(arr[0] > 0){
		cout<<"1\n";
		return;
	}
	int minDiff = arr[1] - arr[0];
	int ans = 1;
	for(int i=1;i<n;i++){
		minDiff = min(arr[i] - arr[i-1],minDiff);
		if(arr[i] <= minDiff){
			ans++;
		}else{
			break;
		}
	}
	cout<<ans<<"\n";

}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}