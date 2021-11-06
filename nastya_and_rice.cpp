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
		int n,a,b,c,d;
		cin>>n>>a>>b>>c>>d;
		int min_rice = a-b;
		int max_rice = a+b;
		int min_bag = c-d;
		int max_bag = c+d;
		if(min_rice * n > max_bag || max_rice * n < min_bag){
			cout<<"No"<<"\n";
		}else{
			cout<<"Yes"<<"\n";
		}
	}
	return 0;
}