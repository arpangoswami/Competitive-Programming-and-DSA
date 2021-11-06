
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool check(vector<int> &loads,int mid,int k){
	int cnt = 0;
	for(int x:loads){
		int req = (ceil)((double)x/(double)mid);
		cnt += req;
	}
	return cnt <= k;
}
int getMaximumLoadServer(int k,vector<int> loads){
	int n = loads.size();
	int minm = 1e9,maxm = 0;
	for(int x:loads){
		minm = min(minm,x);
		maxm += x;
	}
	int low = minm,high = maxm,ans = high;
	while(low <= high){
		int mid = low + (high - low)/2;
		if(check(loads,mid,k)){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	return ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int k;
	cin >> k;
	cout<<getMaximumLoadServer(k,arr)<<"\n";
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