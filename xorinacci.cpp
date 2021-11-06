#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		ll a,b,n;
		cin>>a>>b>>n;
		if(n%3 == 2){
			cout<< (a^b) <<"\n";
		}else if(n%3 == 1){
			cout<<b<<"\n";
		}else{
			cout<<a<<"\n";
		}
	}
	return 0;
}