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
	int n;
	cin >> n;
	vector<string>grid(n);
	for(string &s:grid){
		cin >> s;
	}
	set<vector<pii>> pts;
	vi arr;
	for(int i=0;i<n;i++){
		int cnt = 0;
		vector<pii> pt;
		bool canWin = true;
		for(int j=0;j<n;j++){
			if(grid[i][j] == 'O'){
				canWin = false;
				break;
			}else if(grid[i][j] == '.'){
				cnt++;
				pt.push_back({i+1,j+1});
			}
		}
		if(canWin){
			sort(pt.begin(),pt.end());
			pts.insert(pt);
			arr.push_back(cnt);
		}
	}
	for(int j=0;j<n;j++){
		int cnt = 0;
		bool canWin = true;
		vector<pii> pt;
		for(int i=0;i<n;i++){
			if(grid[i][j] == 'O'){
				canWin = false;
				break;
			}else if(grid[i][j] == '.'){
				pt.push_back({i+1,j+1});
				cnt++;
			}
		}
		if(canWin){
			sort(pt.begin(),pt.end());
			pts.insert(pt);
			arr.push_back(cnt);
		}
	}
	if(arr.empty()){
		cout<<"Impossible\n";
		return;
	}
	int x = *min_element(arr.begin(),arr.end());
	int cnt = 0;
	for(auto v:pts){
		if(v.size() == x){
			cnt++;
		}
	}
	cout<<x<<" "<<cnt<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	#ifndef ONLINE_JUDGE

	freopen("C_input.txt", "r", stdin);

	freopen("C_output.txt", "w", stdout);

	#endif
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}