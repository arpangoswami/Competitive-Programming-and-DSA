#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool check(vector<int> arr,int inc,int n,int k){
	arr[0] += inc;
	int original = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i] * 100 > original * k){
			return false;
		}
		original += arr[i];
	}
	return true;
}
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	int maxm = 0;
	for(int &i:arr){
		cin >> i;
		maxm = max(maxm,i);
	}
	int low = 0,high = maxm * 100,ans = high;
	while(low <= high){
		int mid = (low + high)/2;
		if(check(arr,mid,n,k)){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	cout<<ans<<'\n';
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