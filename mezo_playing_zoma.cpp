#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	while(test--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int left = 0,right = 0;
		for(int i=0;i<n;i++){
			if(s[i] == 'L'){
				left++;
			}else{
				right++;
			}
		}
		cout<<(right + left + 1)<<"\n";
	}
	return 0;
}