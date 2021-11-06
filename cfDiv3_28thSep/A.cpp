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
	int a = 0,b = 0,c = 0;
	for(int i=0;i<n;i++){
		if(s[i] == 'A'){
			a++;
		}else if(s[i] == 'B'){
			b++;
		}else{
			c++;
		}
	}
	//cout<<a<<" "<<b<<" "<<c<<"\n";
	if((n % 2 == 0) && b == (a + c)){
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