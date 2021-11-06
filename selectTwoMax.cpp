#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int binSearch(int left,int right,vector<array<int,3>> &arr,int value){
	int ans = left-1;
	while(left <= right){
		int mid = (left+right)/2;
		if(arr[mid][1] <= value){
			ans = mid;
			left = mid+1;
		}else{
			right = mid-1;
		}
	}
	return ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<array<int,3>> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	if(n == 1){
		cout << arr[0][2] << "\n";
		return;
	}
	sort(arr.begin(),arr.end(),[](array<int,3> &ar1,array<int,3> &ar2){
		return ar1[1] <= ar2[1];
	});
	vi prefMax(n);
	prefMax[0] = arr[0][2];
	for(int i=1;i<n;i++){
		prefMax[i] = max(prefMax[i-1],arr[i][2]);
	}
	int ans = 0;
	for(int i=1;i<n;i++){
		int rIdx = binSearch(0,i-1,arr,arr[i][0]);
		if(rIdx < 0){
			continue;
		}
		ans = max(ans,arr[i][2] + prefMax[rIdx]);
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}