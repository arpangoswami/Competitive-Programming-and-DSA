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
		cin>>n;
		vector<int> arr(2*n);
		for(int i=0;i<2*n;i++){
			cin>>arr[i];
		}
		set<int> st;
		vector<int> sol;
		for(int i=0;i<2*n;i++){
			if(st.count(arr[i]) == 0){
				sol.push_back(arr[i]);
			}
			st.insert(arr[i]);
		}
		for(int x:sol){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	return 0;
}