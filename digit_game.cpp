#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(n % 2 == 0){
		bool breach = false;
		for(int i=2;i<=n;i+=2){
			int digit = s[i-1] - '0';
			if(digit % 2 == 0){
				breach = true;
				break;
			}
		}
		if(breach){
			cout<<2<<"\n";
		}else{
			cout<<1<<"\n";
		}
	}else{
		bool raze = false;
		for(int i=1;i<=n;i+=2){
			int digit = s[i-1] - '0';
			if(digit % 2 != 0){
				raze = true;
				break;
			}
		}
		if(raze){
			cout<<1<<'\n';
		}else{
			cout<<2<<'\n';
		}
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