#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	while(test--){
		int n;
		cin >> n;
		vector<int> arr(n);
		vector<int> req(n);
		int sum = 0;
		for(int i=0;i<n;i++){
			cin >> arr[i];
			sum += arr[i];
		}
		for(int i=0;i<n;i++){
			cin >> req[i];
			if(i > 0){
				req[i]+=req[i-1];
			}
		}
		vector<int> prefix(n);
		prefix[0] = arr[0];
		for(int i=1;i<n;i++){
			prefix[i] = prefix[i-1] + arr[i];
		}
		int minOps = 0;
		for(int i=0;i<(n-1);i++){
			int part1 = prefix[i];
			int part2 = prefix.back() - prefix[i];
			int required = req[i];
			int ops = abs(required-part1);
			minOps = max(minOps,ops);
		}
		cout << minOps <<"\n";
	}
	return 0;
}