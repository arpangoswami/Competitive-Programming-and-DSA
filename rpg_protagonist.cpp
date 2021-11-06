#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int p,f;
	cin >> p >> f;
	int cnts,cntw;
	cin >> cnts >> cntw;
	int s,w;
	cin >> s >> w;
	if(s < w){
		int ans = 0;
		for(int i=0;i<=cnts;i++){
			int youSword = min(i,p/s);
			int followSword = min(cnts-i,f/s);
			int youAxe = min(cntw,(p-s*youSword)/w);
			int followAxe = min(cntw-youAxe,(f-followSword*s)/w);
			ans = max(ans,youSword+followSword+youAxe+followAxe);
		}
		cout<<ans<<"\n";
	}else{
		int ans = 0;
		for(int i=0;i<=cntw;i++){
			int youAxe = min(i,p/w);
			int followAxe = min(cntw-i,f/w);
			int youSword = min(cnts,(p-w*youAxe)/s);
			int followSword = min(cnts-youSword,(f-followAxe*w)/s);
			ans = max(ans,youSword+youAxe+followSword+followAxe);
		}
		cout<<ans<<"\n";
	}

}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}