#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,x;
		cin >> n >> x;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr.begin(),arr.end());
		int ans = 0;
		for(int i=n-1;i>=0;i--){
			if(arr[i] >= x){
				ans++;
			}else{
				int j = i;
				int curr_size = 1;
				while(j>=0 && arr[j]*curr_size < x){
					curr_size++;
					j--;
				}
				if(j>=0){
					ans++;
				}
				i = j;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}