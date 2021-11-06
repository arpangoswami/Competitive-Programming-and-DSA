#include <bits/stdc++.h>
#define int long long
using namespace std;
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
		vector<string> sol;
		int first = arr[0];
		string s1,s2;
		for(int i=0;i<first;i++){
			s1.push_back('a');
			s2.push_back('a');
		}
		for(int i=0;i<120;i++){
			s1.push_back('b');
			s2.push_back('c');
		}
		sol.push_back(s1);
		sol.push_back(s2);
		for(int i=1;i<n;i++){
			int common = arr[i];
			string before = sol.back();
			string s;
			for(int i=0;i<common;i++){
				s.push_back(before[i]);
			}
			char ch = before[common];
			for(int i=0;i<120;i++){
				if(ch == 'z'){
					s.push_back('y');
				}else{
					s.push_back(ch+1);
				}
			}
			sol.push_back(s);
		}
		for(string x:sol){
			cout << x << "\n";
		}
	}
	return 0;
}