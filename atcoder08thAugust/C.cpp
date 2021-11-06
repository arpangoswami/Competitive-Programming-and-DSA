#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
void solveQuestion(){
	ordered_set rowWise;
	ordered_set colWise;
	int h,w,n;
	cin >> h >> w >> n;
	vector<pii> cards(n);
	for(int i=0;i<n;i++){
		cin >> cards[i].ff >> cards[i].ss;
		rowWise.insert(cards[i].ff);
		colWise.insert(cards[i].ss);
	}
	for(int i=0;i<n;i++){
		int x = cards[i].ff,y = cards[i].ss;
		int num1 = rowWise.order_of_key(x);
		int num2 = colWise.order_of_key(y);
		cout << num1 + 1 <<" "<<num2 + 1<<"\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}