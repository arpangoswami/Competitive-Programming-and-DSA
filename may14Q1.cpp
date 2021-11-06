#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		ll n,m;
		cin >> n >> m;
		if(n == 1){
			cout<<0<<endl;
		}
		else if(n == 2){
			cout<<m<<"\n";
		}
		else{
			cout<<2*m<<"\n";
		}
	}
	return 0;
}