#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
ll kadaneSum(vector<ll> &arr){
	ll curr = 0,max_sum = 0;
	int k = arr.size();
	for(int i=0;i<k;i++){
		curr+=arr[i];
		if(curr < 0) curr = 0;
		max_sum = max(max_sum,curr);
	}
	return max_sum; 
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<ll> arr(n);
		ll sm = 0;
		vector<ll> evenPos;
		vector<ll> oddPos;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(i%2 == 0){
				sm+=arr[i];
			}
			if(i > 0 && i % 2 == 0){
				oddPos.push_back(arr[i - 1] - arr[i]);
			}
			else if(i > 0 && i % 2 == 1){
				evenPos.push_back(arr[i] - arr[i-1]);
			}
		}
		cout<<sm + max(kadaneSum(evenPos),kadaneSum(oddPos))<<endl;
	}
	return 0;
}