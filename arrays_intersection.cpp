#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		int n;
		cin >> n;
		map<int,int> mp1;
		map<int,int> mp2;
		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			mp1[x]++;
		}	
		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			mp2[x]++;
		}
		vector<int> solution;
		for(auto it:mp1){
			int val = it.first;
			int times = min(mp1[val],mp2[val]);
			while(times > 0){
				solution.push_back(val);
				times--;
			}
		}
		int sz = solution.size();
		cout << "[";
		for(int i=0;i<(sz-1);i++){
			cout<<solution[i]<<", ";
		}
		cout<<solution.back()<<"]";
	}
	return 0;
}