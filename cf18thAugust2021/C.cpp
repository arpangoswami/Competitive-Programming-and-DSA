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
	int n;
	cin >> n;
	int sq = sqrtl(n);
	if(sq*sq == n){
		cout<<sq<<" "<<1<<"\n";
		return;
	}
	int col = sq+1;
	int row = n - sq*sq;
	if(row <= (sq+1)){
		cout<<row<<" "<<col<<"\n";
		return;
	}
	row = col;
	col = (sq+1)*(sq+1) - n + 1;
	cout << row << " " << col << "\n";
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