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
	int n,m;
	cin >> n >> m;
	vpi arr(m);
	for(int i=0;i<m;i++){
		cin >> arr[i].ff >> arr[i].ss;
	}
	sort(arr.begin(),arr.end(),[](auto &v1,auto &v2){
		if(v1.ss == v2.ss){
			return v1.ff < v2.ff;
		}
		return v1.ss < v2.ss;
	});
	priority_queue<int,vector<int>,greater<int>> pq;
	int heapSum = 0,ans = 0;
	for(int i=0;i<m;i++){
		while((!pq.empty() && pq.top() < arr[i].ss) || (pq.size() >= n)){
			heapSum -= pq.top();
			pq.pop();
		}
		ans = max(ans,arr[i].ff + heapSum + (n-1-pq.size())*arr[i].ss);
		heapSum += arr[i].ff;
		pq.push(arr[i].ff);
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