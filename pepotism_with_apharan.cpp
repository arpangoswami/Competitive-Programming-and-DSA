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
		vector<int> arr1(n+1);
		vector<int> arr2(n+1);
		for(int i=0;i<n;i++){
			cin >> arr1[i];
		}
		for(int i=0;i<n;i++){
			cin >> arr2[i];
		}
		stack<int> st1;
		int j = 0;
		for(int i=0;i<n;i++){
			st1.push(arr1[i]);
			while(!st1.empty() && arr2[j] == st1.top()){
				j++;
				st1.pop();
			}
		}
		bool f = true;
		for(int k=j;k<n && f;k++){
			if(arr2[j] == st1.top()){
				st1.pop();
			}else{
				f = false;
			}
		}
		f = st1.empty();
		string ans = f ? "Possible" : "Not Possible";
		cout << ans << "\n";		
	}
	return 0;
}