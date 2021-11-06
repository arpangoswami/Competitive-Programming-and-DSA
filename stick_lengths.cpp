#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int cost(int val,vector<int> &arr,int n){
	int ct = 0;
	for(int i=0;i<n;i++){
		ct += abs(arr[i]-val);
	}
	return ct;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	int minm = 1e9,maxm = 1;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		maxm = max(maxm,arr[i]);
		minm = min(minm,arr[i]);
	}
	int low = minm,high = maxm,ans = 1e15;
	while(low <= high){
		int mid = (low + high)/2;
		int costMid = cost(mid,arr,n);
		int costMidPlus = cost(mid+1,arr,n);
		int costMidMinus = cost(mid-1,arr,n);
		if(costMid  <= costMidPlus && costMid <= costMidMinus){
			ans = min(costMid,ans);
			break;
		}else if(costMid >= costMidMinus && costMid<=costMidPlus){
			ans = min(ans,costMid);
			high = mid-1;
		}else if(costMid >= costMidPlus && costMid <= costMidMinus){
			ans = min(costMid,ans);
			low = mid+1;
		}
	}
	cout<<ans<<"\n";
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