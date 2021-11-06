#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
void solveQuestion(){
	int n;
	cin >> n;
	vector<bool> marked(2*n+1);
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		marked[arr[i]] = true;
	}
	sort(arr.begin(),arr.end());
	int right = arr[0]+1;
	vector<int> possible(n+1);
	possible[0]++;
	possible[n]++;
	for(int i=0;i<n;i++){
		right = max(right,arr[i]+1);
		while(right <= 2*n && marked[right]){
			right++;
		}
		if(right > 2*n){
			break;
		}else{
			possible[i+1]++;
			right++;
		}
	}
	int left = arr[n-1] - 1;
	for(int i=n-1;i>=0;i--){
		left = min(left,arr[i]-1);
		while(left > 0 && marked[left]){
			left--;
		}
		if(left <= 0){
			break;
		}else{
			int diff = n - i;
			possible[i]++;
			left--;
		}
	}
	int ans = 0;
	for(int i=0;i<=n;i++){
		if(possible[i] == 2){
			ans++;
		}
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}