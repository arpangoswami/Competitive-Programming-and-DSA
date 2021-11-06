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
		int n;
		cin >> n;
		if(n <= 30){
			cout << "NO" << "\n";
		}else if(n == 36){
			cout<<"YES"<<"\n";
			cout<<"6 10 15 5"<<"\n";
		}else if(n == 40){
			cout<<"YES"<<"\n";
			cout<<"6 10 15 9"<<"\n";
		}else if(n == 44){
			cout<<"YES"<<"\n";
			cout<<"6 10 15 13"<<"\n";
		}else{
			cout<<"YES" <<"\n";
			cout <<"6 10 14 ";
			cout<<(n-30)<<"\n";
		}
	}
	return 0;
}