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
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		int size = 1;
		bool allEqual = true;
		for(int i=1;i<n;i++){
			if(arr[i]!=arr[i-1]){
				allEqual = false;
				break;
			}
		}
		if(allEqual){
			cout<<n<<"\n";
		}else{
			cout<<1<<"\n";
		}
	}
	return 0;
}