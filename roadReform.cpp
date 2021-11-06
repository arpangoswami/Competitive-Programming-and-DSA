/*
https://codeforces.com/contest/1468/problem/J
There are n cities and m bidirectional roads in Berland. The i-th road connects the cities xi and yi, and has the speed limit si. The road network allows everyone to get from any city to any other city.

The Berland Transport Ministry is planning a road reform.

First of all, maintaining all m roads is too costly, so m−(n−1) roads will be demolished in such a way that the remaining (n−1) roads still allow to get to any city from any other city. Formally, the remaining roads should represent an undirected tree.

Secondly, the speed limits on the remaining roads might be changed. The changes will be done sequentially, each change is either increasing the speed limit on some road by 1, or decreasing it by 1. Since changing the speed limit requires a lot of work, the Ministry wants to minimize the number of changes.

The goal of the Ministry is to have a road network of (n−1) roads with the maximum speed limit over all roads equal to exactly k. They assigned you the task of calculating the minimum number of speed limit changes they have to perform so the road network meets their requirements.

For example, suppose the initial map of Berland looks like that, and k=7:


Then one of the optimal courses of action is to demolish the roads 1–4 and 3–4, and then decrease the speed limit on the road 2–3 by 1, so the resulting road network looks like that:


Input
The first line contains one integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains three integers n, m and k (2≤n≤2⋅105; n−1≤m≤min(2⋅105,n(n−1)2); 1≤k≤109) — the number of cities, the number of roads and the required maximum speed limit, respectively.

Then m lines follow. The i-th line contains three integers xi, yi and si (1≤xi,yi≤n; xi≠yi; 1≤si≤109) — the cities connected by the i-th road and the speed limit on it, respectively. All roads are bidirectional.

The road network in each test case is connected (that is, it is possible to reach any city from any other city by traveling along the road), and each pair of cities is connected by at most one road.

The sum of n over all test cases does not exceed 2⋅105. Similarly, the sum of m over all test cases does not exceed 2⋅105.

Output
For each test case, print one integer — the minimum number of changes the Ministry has to perform so that the maximum speed limit among the remaining (n−1) roads is exactly k.

Example
inputCopy
4
4 5 7
4 1 3
1 2 5
2 3 8
2 4 1
3 4 4
4 6 5
1 2 1
1 3 1
1 4 2
2 4 1
4 3 1
3 2 1
3 2 10
1 2 8
1 3 10
5 5 15
1 2 17
3 1 15
2 3 10
1 4 14
2 5 8
outputCopy
1
3
0
0
Note
The explanation for the example test:

The first test case is described in the problem statement.

In the second test case, the road network initially looks like that:


The Ministry can demolish the roads 1–2, 3–2 and 3–4, and then increase the speed limit on the road 1–4 three times.

In the third test case, the road network already meets all the requirements.

In the fourth test case, it is enough to demolish the road 1–2 so the resulting road network meets the requirements.
*/
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
class dsu{
public:
	int n;
	vector<int> parent;
	vector<int> height;
	dsu(int _n){
		n = _n;
		parent.resize(n+1);
		height.resize(n+1);
		for(int i=1;i<=n;i++){
			parent[i] = i;
		}
	}
	int findPar(int x){
		if(parent[x] == x){
			return x;
		}
		int p = findPar(parent[x]);
		parent[x] = p;
		return p;
	}
	void unite(int x,int y){
		int x_par = findPar(x),y_par = findPar(y);
		if(x_par == y_par){
			return;
		}
		if(height[x_par] < height[y_par]){
			parent[x_par] = y_par;
		}else{
			parent[y_par] = x_par;
		}
	}
};
void solveQuestion(){
	int n,m,k;
	cin >> n >> m >> k;
	dsu d(n+1);
	vector<array<int,3>> ar(m);
	for(int i=0;i<m;i++){
		cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
	}
	sort(ar.begin(),ar.end(),[](auto &a1,auto &a2){
		return (a1[2] < a2[2]);
	});
	int cmp = n;
	int ans = 0;
	int idx = -1;
	for(int i=0;i<m && cmp > 1;i++){
		if(d.findPar(ar[i][0]) == d.findPar(ar[i][1])){
			continue;
		}
		d.unite(ar[i][0],ar[i][1]);
		if(ar[i][2] > k){
			ans += (ar[i][2] - k);
		}
		cmp--;
		if(cmp == 1){
			idx = i;
		}
	}
	int add = abs(ar[idx][2] - k);
	if(ar[idx][2] > k){
		ans -= add;
	}
	
	for(int i=idx;i<m;i++){
		add = min(add,abs(ar[i][2]-k));
	}
	cout<<ans + add<<"\n";
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