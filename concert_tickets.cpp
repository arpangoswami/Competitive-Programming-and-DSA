/*
Concert Tickets
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.

Each customer announces the maximum price he or she is willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

Input

The first input line contains integers n and m: the number of tickets and the number of customers.

The next line contains n integers h1,h2,…,hn: the price of each ticket.

The last line contains m integers t1,t2,…,tm: the maximum price for each customer.

Output

Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.

If a customer cannot get any ticket, print −1.

Constraints
1≤n,m≤2⋅105
1≤hi,ti≤109
Example

Input:
5 3
5 3 7 8 5
4 8 3

Output:
3
8
-1
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	multiset<int> mset;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		mset.insert(x);
	}
	vector<int> prices(m);
	for(int i=0;i<m;i++){
		int x;
		cin >> x;
		if(mset.empty() || x < *(mset.begin())){
			prices[i] = -1;
			continue;
		}
		auto it = mset.lower_bound(x);
		if(it == mset.end() || (*it) > x){
			--it;
		}
		prices[i] = (*it);
		mset.erase(it);
	}
	for(int x:prices){
		cout<<x<<"\n";
	}

}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}