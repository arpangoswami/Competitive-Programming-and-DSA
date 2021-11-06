#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n0,n1,n2;
		cin>>n0>>n1>>n2;
		string ans = "";
		if(n1 == 0){
			if(n0 == 0){
				for(int i=0;i<=n2;i++){
					ans.push_back('1');
				}
			}
			else{
				for(int i=0;i<=n0;i++){
					ans.push_back('0');
				}
			}
		}
		else{
			for(int i=0;i<=n1;i++){
				ans.push_back('1');
				i++;
				if(i>n1){
					break;
				}
				ans.push_back('0');
			}
			for(int i=0;i<n0;i++){
				ans.insert(1,"0");
			}
			for(int i=0;i<n2;i++){
				ans = '1' + ans;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}		