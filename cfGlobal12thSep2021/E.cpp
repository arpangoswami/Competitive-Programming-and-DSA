#include <bits/stdc++.h>
#include <cstdlib>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
const int MOD = 1e9 + 7;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
struct cmp{
	bool operator()(pii &p1,pii &p2){
		if(p1.ff == p2.ff){
			return p1.ss < p2.ss;
		}
		return p1.ff > p2.ff;
	}
};
void solveQuestion(){
	int m,n;
	cin >> m >> n;
	int sz = m*n;
	vi arr(sz);
	vector<vector<int>> grid(m,vector<int>(n));
	for(int &i:arr){
		cin >> i;
	}
	vi temp(sz);
	for(int i=0;i<sz;i++){
		temp[i] = arr[i];
	}
	sort(temp.begin(),temp.end());
	int x = 0,y = 0,idx = 0;
	for(int i=0;i<sz;i++){
		grid[x][y] = temp[i];
		y++;
		if(y == n){
			y = 0;
			x++;
		}
	}
	map<int,priority_queue<pii,vector<pii>,cmp>> position;
	for(int i=0;i<m;i++){
		int last = 2e9 + 1;
		for(int j=n-1;j>=0;j--){
			int num = grid[i][j];
			if(num != last){
				position[num].push({i,j});
			}
			last = num;
		}
	}
	vector<vector<int>> empty(m,vector<int>(n));
	vector<ordered_set> helper(m);
	int ans = 0;
	for(int i=0;i<sz;i++){
		int num = arr[i];
		int yPos = position[num].top().ss, xPos = position[num].top().ff;
		position[num].pop();
		int add = helper[xPos].order_of_key(yPos);
		ans += add;
		helper[xPos].insert(yPos);
		empty[xPos][yPos] = i;
		if(yPos > 0 && grid[xPos][yPos-1] == num){
			position[num].push({xPos,yPos-1});
		}
	}
	cout << ans << "\n";
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