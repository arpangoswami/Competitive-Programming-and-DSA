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
	string s;
	cin >> s;
	int n = s.size();
	int seg = 0;
	if(s[0] == '0'){
		seg++;
	}
	for(int i=1;i<n;i++){
		if(s[i] == '0' && s[i-1] != '0'){
			seg++;
		}
	}
	seg = min(2LL,seg);
	cout<<seg<<"\n";
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