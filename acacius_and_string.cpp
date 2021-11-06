#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
const string sol = "abacaba";
int count_occur(const string &s){
	int cnt = 0;
	int n = s.size();
	for(int i=0;i<=(n-7);i++){
		if(s.substr(i,7) == sol){
			cnt++;
		}
	}
	return cnt;
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool flag = false;
		for(int i=0;i<=(n-7) && !flag;i++){
			string temp = s;
			bool possible = true;
			for(int j=0;j<7;j++){
				if(temp[i+j]!=sol[j] && temp[i+j]!='?'){
					possible = false;
					break;
				}
				temp[i+j] = sol[j];
			}
			if(possible && count_occur(temp) == 1){
				flag = true;
				for(int i=0;i<n;i++){
					if(temp[i] == '?'){
						temp[i] = 'd';
					}
				}
				cout << "Yes" <<"\n";
				cout << temp <<"\n";
			}
		}
		if(!flag){
			cout<<"No"<<"\n";
		}
		
	}
	return 0;
}