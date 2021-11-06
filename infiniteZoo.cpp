#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int q;
	cin >> q;
	while(q--){
		int u,v;
		cin >> u >> v;
		if(u == v){
			cout<<"YES"<<'\n';
			continue;
		}else if(u > v){
			cout<<"NO"<<'\n';
			continue;
		}else{
			if(perfectPower2(v)){
				cout<<"YES"<<'\n';
				continue;
			}
			else{
				int m = 1LL;
				while(m < u && m * 2 <= v){
					m *= 2LL;
				}
				u = max(u,m);
				if(subMask(v-u,v)){
					cout<<"YES"<<'\n';
				}else{
					cout<<"NO"<<'\n';
				}
			}
		}
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}