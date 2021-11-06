#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
		int n = s.size();
		int cur = 0;
		ll res = 0;
		for(int i=0;i<n;i++){
			if(s[i] == '+'){
				cur++;
			}
			else{
				cur--;
			}
			if(cur < 0){
				cur = 0;
				res+=(i+1);
			}
			//cout<<"res: "<<res<<endl;
		}
		res+=n;
		cout<<res<<endl;
	}
	return 0;
}