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
		string s;
		cin >> s;
		vector<int> sol(n);
		int ans = 0;
		set<int> ones;
		set<int> zeros;
		for(int i=0;i<n;i++){
			if(s[i] == '0'){
				if(!ones.empty()){
					auto it = ones.begin();
					int f = *it;
					sol[i] = f;
					ones.erase(f);
					zeros.insert(f); 
					//oneEnd--;
					//zeroEnd++;
				}else{
					ans++;
					sol[i] = ans;
					//zeroEnd++;
					zeros.insert(ans);
				}
			}else{
				if(!zeros.empty()){
					auto it = zeros.begin();
					int f = *it;
					sol[i] = f;
					zeros.erase(f);
					ones.insert(f);
					//zeroEnd--;
					//oneEnd++;
				}else{
					ans++;
					sol[i] = ans;
					//oneEnd++;
					ones.insert(ans);
				}
			}
		}
		cout << ans << "\n";
		for(int x:sol){
			cout << x << " ";
		}
		cout<<"\n";
	}
	return 0;
}