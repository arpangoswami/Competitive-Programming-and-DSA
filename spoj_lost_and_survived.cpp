/*
LOSTNSURVIVED - Lost and survived
#disjoint-set-2
On September 22, 2004, Oceanic Flight 815 crashed on a mysterious island somewhere in the pacific.

There actually were survivors in the crash , N survivors . The mysterious island kept on moving in space - time, so no rescue reached them.

Initially every survivor was on his own .But soon they realized there are these “The Others” (Scientists of damn Dharma Initiative) on this Island too.

So to protect themselves from mad Scientists they started uniting into groups after Dr. Shephard  said  “ Live together Die alone ”.

You have to handle Q queries; which consist of two survivors becoming friends and thereby uniting there respective groups into a  larger group.

After each query, output the difference between the group of largest size and group of smallest size at that time.

If there is only one group, output 0. At first, everyone is in their own group.

Also note, if the two survivors in the query are already in the  same group, print the current answer, and skip merging groups.

Also do comment if you have watched Lost :-p

Input
 

The first line consists of two space separated integers, N and QThe next Q line consists of two integers, A and B, meaning that the groups involving survivor A and survivor B unite into a larger group.
The first line consists of two space separated integers, N and Q

 

The next Q line consists of two integers, A and B, meaning that 

survivor A and survivor B became friends uniting there groups.

 

Output
Output Q lines, the answer after each query.

 

1<=N<=100000

1<=Q<=100000

Example
Input:
5 3
1 2
2 3
5 4
Output:
1
2
1

*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int findParent(int x,vector<int> &parent){
	if(x == parent[x]){
		return x;
	}
	int par = findParent(parent[x],parent);
	parent[x] = par;
	return par;
}
void unionRank(int x,int y,vector<int> &parent,vector<int> &rank){
	if(rank[x] > rank[y]){
		parent[y] = x;
	}
	else if(rank[x] < rank[y]){
		parent[x] = y;
	}else{
		parent[x] = y;
		rank[y]++;
	}
}
void solveQuestion(){
	int n,q;
	cin >> n >> q;
	vector<int> parent(n+1);
	vector<int> rank(n+1);
	multiset<int> mset;
	unordered_map<int,int> mp;
	for(int i=1;i<=n;i++){
		parent[i] = i;
	}
	for(int i=1;i<=n;i++){
		mset.insert(1);
	}
	for(int i=1;i<=n;i++){ 
		mp[i] = 1;
	}
	while(q--){
		int u,v;
		cin >> u >> v;
		int x_rep = findParent(u,parent);
		int y_rep = findParent(v,parent);
		if(x_rep != y_rep){
			int x_size = mp[x_rep];
			int y_size = mp[y_rep];
			unionRank(x_rep,y_rep,parent,rank);
			multiset<int>::iterator it = mset.find(x_size);
			mset.erase(it);
			multiset<int>::iterator it2 = mset.find(y_size);
			mset.erase(it2);
			unionRank(x_rep,y_rep,parent,rank);
			int sum = x_rep + y_rep;
			x_rep = findParent(x_rep,parent);
			y_rep = sum - x_rep;
			mp[x_rep] = (x_size + y_size);
			mp.erase(y_rep);
			mset.insert(x_size + y_size);
		}
		int val = *(mset.rbegin());
		val -= *(mset.begin());
		cout<<val<<"\n";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}