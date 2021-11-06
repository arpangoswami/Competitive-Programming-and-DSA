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
	int x,y;
	cin >> x >> y;
	if(x > y){
		swap(x,y);
	}
	if(x == 0 && y == 0){
		cout<<"0\n";
		return;
	}
	if(x == y){
		cout<<"1\n";
		return;
	}
	int diff = (y-x);
	if(diff % 2 == 0){
		cout<<"2\n";
	}else{
		cout<<"-1\n";
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