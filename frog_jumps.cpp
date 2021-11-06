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
		string s;
		cin>>s;
		n = s.size();
		vector<int> rights;
		for(int i=0;i<n;i++){
			if(s[i] == 'R'){
				rights.push_back(i);
			}
		}
		int N = rights.size();
		if(N == 0){
			cout<<(n+1)<<"\n";
		}else{
			int min_jump = rights[0] + 1 - 0;
			for(int i=1;i<N;i++){
				min_jump = max(min_jump,rights[i] - rights[i-1]);
			}
			min_jump = max(min_jump,n - rights.back());
			cout<<min_jump<<"\n";
		}
	}
	return 0;
}