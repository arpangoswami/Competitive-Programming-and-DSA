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
		if(n == 1){
			cout << 0 << "\n";
			continue;
		}
		sort(arr.begin(),arr.end());
		int posLow = 1,posHigh = arr.back() + arr[n-2];
		int maxTeams = 0;
		for(int sum=posLow;sum<=posHigh;sum++){
			int i = 0,j = n-1;
			int teams = 0;
			while(i < j){
				if(arr[i] + arr[j] < sum){
					i++;
				}else if(arr[i] + arr[j] > sum){
					j--;
				}else{
					i++;
					j--;
					teams++;
				}
			}
			maxTeams = max(maxTeams,teams);
		}
		cout << maxTeams << "\n";
	}
	return 0;
}