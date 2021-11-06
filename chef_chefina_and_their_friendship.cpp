#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		string s;
		cin >> s;
		int n = s.size();
		int ans = 0;
		for(int i=1;i<(n-2);i+=2){
			int len1 = i+1,len2 = n-len1-1;
			string s1 = s.substr(0,len1/2);
			string s2 = s.substr(len1/2,len1/2);
			bool f = true;
			for(int k=0;k<len1/2;k++){
				if(s1[k]!=s2[k]){
					f = false;
					break;
				}
			}
			if(f){
				string s3 = s.substr(len1,len2/2);
				string s4 = s.substr(len1 + len2/2,len2/2);
				for(int k=0;k<len1/2;k++){
					if(s1[k]!=s2[k]){
						f = false;
						break;
					}
				}
			}
			if(f){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}