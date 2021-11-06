/*
B. Shuffle
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array consisting of n integers a1, a2, ..., an. Initially ax=1, all other elements are equal to 0.

You have to perform m operations. During the i-th operation, you choose two indices c and d such that li≤c,d≤ri, and swap ac and ad.

Calculate the number of indices k such that it is possible to choose the operations so that ak=1 in the end.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases. Then the description of t testcases follow.

The first line of each test case contains three integers n, x and m (1≤n≤109; 1≤m≤100; 1≤x≤n).

Each of next m lines contains the descriptions of the operations; the i-th line contains two integers li and ri (1≤li≤ri≤n).

Output
For each test case print one integer — the number of indices k such that it is possible to choose the operations so that ak=1 in the end.

Example
inputCopy
3
6 4 3
1 6
2 3
5 5
4 1 2
2 4
1 2
3 3 2
2 3
1 2
outputCopy
6
2
3
Note
In the first test case, it is possible to achieve ak=1 for every k. To do so, you may use the following operations:

swap ak and a4;
swap a2 and a2;
swap a5 and a5.
In the second test case, only k=1 and k=2 are possible answers. To achieve a1=1, you have to swap a1 and a1 during the second operation. To achieve a2=1, you have to swap a1 and a2 during the second operation.

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
bool check(set<pii> &st,pii p){
	for(auto x:st){
		if(((p.first>=x.first && p.first<=x.second) || (p.second>=x.first && p.second<=x.second)) || ((x.first>=p.first && x.first<=p.second) || (x.second>=p.first && x.second<=p.second))){
			return true;
		}
	}
	return false;
}
vector<pii> mergeInv(set<pii>& v){
	vector<pii> sol;
	if(v.size() == 0){
		return sol;
	}
	sol.push_back(*(v.begin()));
	auto it = v.begin();
	++it;
	if(v.size() < 2){
		return sol;
	}
	int f = 0;
	for(;it!=v.end();++it){
		pii p = *it;
		if(p.first<=sol[f].second){
			sol[f].second = max(p.second,sol[f].second);
		}
		else{
			f++;
			sol.push_back(*it);
		}
	}
	return sol;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		set<pii> st;
		ll n,x,m;
		cin>>n>>x>>m;
		st.insert({x,x});
		while(m--){
			ll l,r;
			cin>>l>>r;
			bool chk= check(st,{l,r});
			if(chk){
				st.insert({l,r});
			}
		}
		vector<pii> inv;
		inv = mergeInv(st);
		ll k = 0;
		for(pii x:inv){
			k+=(x.second-x.first+1);
		}
		cout<<k<<endl;
	}
	return 0;
}