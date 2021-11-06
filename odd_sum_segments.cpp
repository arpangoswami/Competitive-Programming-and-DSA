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
		int n,k;
		cin >> n >> k;
		vi arr(n);
		int cnt = 0;
		for(int i=0;i<n;i++){
			cin >> arr[i];
			if(arr[i]%2 == 1){
				cnt++;
			}
		}
		int diff = cnt - k;
		if(cnt < k){
			cout << "NO" <<"\n";
		}else if(diff % 2 == 1){
			cout << "NO" <<"\n";
		}else{
			cnt = 0;
			int i = 0;
			cout << "YES" <<"\n";
			while(cnt < (k-1)){
				if(arr[i] % 2 == 1){
					cout << i+1 <<" ";
					cnt++;
				}
				i++;
			}
			cout<<n<<"\n";
		}
	}
	return 0;
}