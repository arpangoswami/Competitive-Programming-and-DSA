#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
void solveQuestion(){
	string s;
	cin >> s;
	int n = s.size();
	int lastU = 0,firstM = n+1;
	for(int i=0;i<n;i++){
		if(firstM > n && s[i] == 'M'){
			firstM = i;
		}
		if(s[i] == 'U'){
			lastU = i;
		}
	}
	if(firstM < lastU){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
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