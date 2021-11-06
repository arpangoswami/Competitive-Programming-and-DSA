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
		ll a,b,n,m;
		cin>>a>>b>>n>>m;
		if((n + m) > (a + b)){
			cout<<"No"<<"\n";
		}else{
			if(m > min(a,b)){
				cout<<"No"<<"\n";
			}else{
				cout<<"Yes"<<"\n";
			}
		}
	}
	return 0;
}