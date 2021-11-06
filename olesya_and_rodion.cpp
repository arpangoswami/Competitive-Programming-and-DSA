#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,t;
	cin>>n>>t;
	if(t == 10 && n == 1){
		cout<<-1<<endl;
	}else if(n == 1){
		cout<<t<<endl;
	}else{
		string ans;
		if(t!=10){
			ans.push_back((char)(48 + t));
			for(int i=1;i<n;i++){
				ans.push_back('0');
			}
		}else{
			ans.push_back('1');
			for(int i=1;i<n;i++){
				ans.push_back('0');
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}