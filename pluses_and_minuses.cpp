#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;
		int res = 0;
		for(int i=0;i<=inf;i++){
			int cur = i;
			bool ok = true;
			int n = s.size();
			for(int j=0;j<n;j++){
				res++;
				if(s[j] == '+'){
					cur++;
				}else{
					cur--;
				}
				if(cur < 0){
					ok = false;
					break;
				}
			}
			cout<<"res: "<<res<<endl;
			if(ok){
				break;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}