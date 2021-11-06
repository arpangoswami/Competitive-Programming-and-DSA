/*
https://www.codechef.com/LRNDSA07/problems/FROGV
Nobody knows, but N frogs live in Chef's garden.

Now they are siting on the X-axis and want to speak to each other. One frog can send a message to another one if the distance between them is less or equal to K.

Chef knows all P pairs of frogs, which want to send messages. Help him to define can they or not!

Note : More than 1 frog can be on the same point on the X-axis.
 

Input
The first line contains three integers N, K and P.
The second line contains N space-separated integers A1, A2, ..., AN denoting the x-coordinates of frogs".
Each of the next P lines contains two integers A and B denoting the numbers of frogs according to the input.
 

Output
For each pair print "Yes" without a brackets if frogs can speak and "No" if they cannot.
 

Constraints
1 ≤ N, P ≤ 10^5
0 ≤ Ai, K ≤ 10^9
1 ≤ A, B ≤ N
 

Example
Input:
5 3 3
0 3 8 5 12
1 2
1 3
2 5

Output:
Yes
Yes
No
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int findParent(int x,unordered_map<int,int> &parent){
	if(parent[x] == x){
		return x;
	}
	int p = findParent(parent[x],parent);
	parent[x] = p;
	return p;
}
void unionRank(int x,int y,unordered_map<int,int> &parent,unordered_map<int,int> &rank){
	int x_rep = findParent(x,parent),y_rep = findParent(y,parent);
	if(x_rep == y_rep){
		return;
	}
	else if(rank[x_rep]>rank[y_rep]){
		parent[y_rep] = x_rep;
	}
	else if(rank[y_rep]>rank[x_rep]){
		parent[x_rep] = y_rep;
	}
	else{
		parent[y_rep] = x_rep;
		rank[x_rep]++;
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k,p;
	cin>>n>>k>>p;
	unordered_map<int,int> parent;
	unordered_map<int,int> rank;
	vector<int> x_co(n);
	vector<int> x_co_sorted(n);
	set<int> appeared;
	for(int i=0;i<n;i++){
		cin >> x_co[i];
		x_co_sorted[i] = x_co[i];
		parent[x_co[i]] = x_co[i];
		rank[x_co[i]] = 0;
	}
	sort(x_co_sorted.begin(),x_co_sorted.end());//O(nlogn)
	for(int i=0;i<n;i++){
		auto it = prev(appeared.end());
		auto it = appeared.lower_bound(x_co_sorted[i]-k);
		if(it!=appeared.end()){
			if((*it)<=x_co_sorted[i]+k){
				unionRank(*it,x_co_sorted[i],parent,rank);//O(nlogn)
			}
		}
		appeared.insert(x_co_sorted[i]);
	}
	for(int i=0;i<p;i++){
		int x,y;
		cin>>x>>y;
		if(findParent(x_co[x-1],parent) == findParent(x_co[y-1],parent)){
			cout<<"Yes"<<"\n";
		}
		else{
			cout<<"No"<<"\n";
		}
	}
	return 0;
}