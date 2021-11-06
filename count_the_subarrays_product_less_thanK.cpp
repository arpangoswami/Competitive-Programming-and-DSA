#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	int curr = 1;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int i = 0,ans = 0;
	for(int j=0;j<n;j++){
		curr *= arr[j];
		if(curr < k){
			ans += (j-i+1);
		}else{
			while(curr >= k){
				curr /= arr[i++];
			}
			ans += (j-i+1);
		}
	}
	cout<<ans<<"\n";	
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}