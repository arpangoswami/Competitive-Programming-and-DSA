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
	vector<vector<int>> input(n);
	priority_queue<int,vector<int>,greater<int>> pq;
	int ans = 0;
	for(int i=0;i<n;i++){
		int sz;
		cin >> sz;
		input[i].resize(sz);
		for(int j=0;j<sz;j++){
			cin >> input[i][j];
		}
		int left = 0;
		vector<int> segments;
		for(int j=0;j<(sz-1);j++){
			if(input[i][j] > input[i][j+1]){
				segments.push_back(j-left+1);
				pq.push(j-left+1);
				left = j+1;	
			}
		}
		segments.push_back(sz-left);
		pq.push(sz-left);
		int sum = accumulate(segments.begin(),segments.end(),0);
		int maxm = *max_element(segments.begin(),segments.end());
		ans += (sum - maxm);
	}
	while(pq.size() > 1){
		int t1 = pq.top();
		pq.pop();
		int t2 = pq.top();
		pq.pop();
		ans += (t1 + t2);
		pq.push(t1+t2);
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