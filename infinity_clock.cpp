#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<int> change(vector<int> &arr){
	int n = arr.size();
	vector<int> ans(n);
	int maxm = -1e10;
	for(int i=0;i<n;i++){
		maxm = max(maxm,arr[i]);
	}
	for(int i=0;i<n;i++){
		ans[i] = maxm - arr[i];
	}
	return ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin >> n >> k;
		vector<int> arr(n);
		vector<int> arr1(n);
		vector<int> arr2(n);
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		arr1 = change(arr);
		arr2 = change(arr1);
		if(k%2 == 0){
			for(int x:arr2){
				cout<<x<<" ";
			}
			cout<<"\n";
		}else{
			for(int x:arr1){
				cout<<x<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}