
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
int removeProduct(int num,vector<int> ids,int rem){
	priority_queue<int,vector<int>,greater<int>> pq;
	map<int,int> mp;
	for(int x:ids){
		mp[x]++;
	}
	for(auto it:mp){
		pq.push(it.second);
	}
	int removed = 0;
	while(!pq.empty() && removed < rem){
		int freq = pq.top();
		if(freq + removed > rem){
			break;
		}else{
			removed += freq;
			pq.pop();
		}
	}
	return pq.size();
}
const int INF = 2e9;
vector<int> getTimes(int numCustomers,vector<int> arrTime,vector<int> direction){
	vector<queue<int>> q(2);
	arrTime.push_back(INF);
	vector<int> ans(numCustomers);
	for(int i=0,time=arrTime[0],lastPicked = -1;i<numCustomers;i++){
		q[direction[i]].push(i);
		while(time < arrTime[i+1]){
			if(!q[1].empty() && (lastPicked == -1 || lastPicked == 1)){
				ans[q[1].front()] = time;
				q[1].pop();
				time++;
				lastPicked = 1;
			}else if(!q[0].empty()){
				ans[q[0].front()] = time;
				q[0].pop();
				time++;
				lastPicked = 0;
			}else{
				time = arrTime[i+1];
				lastPicked = -1;
			}
		}
	}
	return ans;
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	cout << removeProduct(6,{1,1,1,2,3,2},2) << "\n";
	vector<int> v = getTimes(4,{0,0,1,5},{0,1,1,0});
	for(int x:v){
		cout<<x<<" ";
	}
	return 0;
}