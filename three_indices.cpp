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
		int f = -1,s = -1,t = -1;
		for(int i=0;i<=(n-3);i++){
			if(arr[i] < arr[i+1] && arr[i+1] > arr[i+2]){
				f = i;
				s = i+1;
				t = i+2;
				break;
			}
		}
		if(f == -1){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
			cout<<f+1<<" "<<s+1<<" "<<t+1<<"\n";
		}
	}
	return 0;
}