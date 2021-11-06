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
	int n,k;
	cin >> n >> k;
	vi one;
	vi two;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	sort(arr.begin(),arr.end());
	int gap = arr[0] - 1;
	if(gap >= 1){
		one.push_back(gap);
	}
	gap = k - arr.back();
	if(gap >= 1){
		one.push_back(gap);
	}
	for(int i=1;i<n;i++){
		int gap = arr[i] - arr[i-1] - 1;
		if(gap >= 2){
			two.push_back(gap);
			one.push_back((gap+1)/2);
		}else if(gap == 1){
			one.push_back(1LL);
		}
	}
	sort(one.begin(),one.end());
	sort(two.begin(),two.end());
	int nicePick = 0;
	sort(one.begin(),one.end());
	if(one.size() >= 2){
		nicePick = one[one.size()-1] + one[one.size()-2];
	}else if(one.size() == 1){
		nicePick = one[one.size()-1];
	}
	if(!two.empty()){
		nicePick = max(nicePick,two.back());
	}
	double ans = (double)nicePick/(double)k;
	cout << fixed << setprecision(9) << ans << endl;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveQuestion();
	}
	return 0;
}