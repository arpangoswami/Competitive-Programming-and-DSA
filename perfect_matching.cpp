#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	int ans = 1;
	unordered_map<int,int> mp1;
	for(int i=0;i<n;i++){
		string s;
		getline(cin, s, ',');
		istringstream ss2(s);
		for(int i;ss2 >> i;){
			mp1[i]++;
			if(ss2.peek() == '&'){
				ss2.ignore();
			}
		}
	}
	cin >> n;
	unordered_map<int,int> mp2;
	for(int i=0;i<n;i++){
		string s;
		getline(cin, s, ',');
		istringstream ss2(s);
		int cnt = 0;
		for(int i;ss2 >> i;){
			mp2[i]++;
			cnt++;
			if(ss2.peek() == '&'){
				ss2.ignore();
			}
		}
		ans = max(ans,cnt);
	}
	
	for(auto it:mp1){
		ans = max(ans,it.second);
	}
	for(auto it:mp2){
		ans = max(ans,it.second);
	}
	cout<<ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}