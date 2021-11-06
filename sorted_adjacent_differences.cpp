#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pr;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr.begin(),arr.end());
		vector<int> sol(n);
		int j = n/2,i = j-1,k = 0;
		while(k<n){
			sol[k++] = arr[j++];
			if(k == n) break;
			sol[k++] = arr[i--];
		}
		for(int x:sol){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	return 0;
}