#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
void solveQuestion(){
	int a,b,c,m;
	cin >> a >> b >> c >> m;
	int minAdj = max({0LL,a - (b+c+1),b - (a+c+1),c - (a+b+1)});
	int maxAdj = max(0LL,a+b+c-3);
	if(m >= minAdj && m <= maxAdj){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}