#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		int n,d;
		cin >> n >> d;
		vector<int>arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}	
		sort(arr.begin(),arr.end());
		int ans = 0;
		int i = 0;
		while(i<(n-1)){
			if(arr[i]+d>=arr[i+1]){
				ans++;
				i+=2;
			}else{
				i++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}