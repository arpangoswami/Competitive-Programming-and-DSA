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
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int len = (n/2);
	for(int i=0;i<(n+1)/2;i++){
		if(s[i] == '0'){
			int l1 = i+1,l2 = i+2,r1 = l1 + len,r2 = l2 + len - 1;
			cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
			return;
		}
	}
	bool allOnes = true;
	for(int i=(n+1)/2;i<n;i++){
		if(s[i] == '0'){
			int l1 = 1,r1 = i+1,l2 = 1,r2 = i;
			cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
			return;
		}
	}
	if(allOnes){
		cout<<1<<" "<<len<<" "<<2<<" "<<len+1<<"\n";
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