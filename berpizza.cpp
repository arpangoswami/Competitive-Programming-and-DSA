#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
struct cmp{
	bool operator()(pii &p1,pii &p2){
		if(p1.ss == p2.ss){
			return p1.ff > p2.ff;
		}
		return p1.ss < p2.ss;
	}
};
void solveQuestion(){
	priority_queue<pii,vector<pii>,cmp> pq;
	queue<int> q;
	set<int> customersServed;
	int queries;
	cin >> queries;
	int num = 1;
	while(queries--){
		int type;
		cin >> type;
		if(type == 1){
			q.push(num);
			int money;
			cin >> money;
			pq.push({num,money});
			num++;
		}else if(type == 2){
			while(customersServed.count(q.front())){
				q.pop();
			}
			customersServed.insert(q.front());
			cout<<q.front()<<" ";
			q.pop();
		}else if(type == 3){
			while(customersServed.count((pq.top()).ff)){
				pq.pop();
			}
			customersServed.insert(pq.top().ff);
			cout<<pq.top().ff<<" ";
			pq.pop();
		}
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