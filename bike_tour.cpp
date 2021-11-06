#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int ans = 0;
		for(int i=1;i<(n-1);i++){
			if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
				ans++;
			}
		}
		cout<<"Case #"<<t<<":"<<" "<<ans<<"\n";
	}
	return 0;
}