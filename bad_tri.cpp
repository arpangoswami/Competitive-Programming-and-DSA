#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i=0;i<n;i++) cin >> arr[i];
		sort(arr.begin(),arr.end());
		int low1 = arr[0],low2 = arr[1],high = arr.back();
		if(low1 + low2 > high){
			cout<<-1<<"\n";
		}else{
			cout<<1<<" "<<2<<" "<<n<<"\n";
		}
	}
	return 0;
}