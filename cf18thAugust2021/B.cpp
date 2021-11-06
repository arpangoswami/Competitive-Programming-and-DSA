#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int a,b,c;
	cin >> a >> b >> c;
	int maxNum = 2*abs(a-b);
	if(max({a,b,c}) > maxNum){
		cout<<"-1\n";
		return;
	}
	int num = (c + (maxNum/2)) > maxNum ? (c - (maxNum/2)) : (c + (maxNum/2));
	cout << num << "\n"; 
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