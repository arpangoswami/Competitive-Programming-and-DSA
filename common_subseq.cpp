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
		int n,m;
		cin >> n >> m;
		vector<int> arr1(n);
		vector<int> arr2(m);
		map<int,int> mp1,mp2;
		for(int i=0;i<n;i++){
			cin >> arr1[i];
			mp1[arr1[i]]++;
		}
		for(int j=0;j<m;j++){
			cin >> arr2[j];
			mp2[arr2[j]]++;
		}
		int sz = 0,ans = -1;
		bool flag = false;
		for(auto it:mp1){
			if(mp2.count(it.first)){
				sz = 1;
				ans = it.first;
				flag = true;
				break;
			}
		}
		if(flag){
			cout << "YES"<<"\n";
			cout << sz <<" "<<ans<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}