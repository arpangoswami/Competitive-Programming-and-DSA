/*
Traffic Lights
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
There is a street of length x whose positions are numbered 0,1,…,x. Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.

Your task is to calculate the length of the longest passage without traffic lights after each addition.

Input

The first input line contains two integers x and n: the length of the street and the number of sets of traffic lights.

Then, the next line contains n integers p1,p2,…,pn: the position of each set of traffic lights. Each position is distinct.

Output

Print the length of the longest passage without traffic lights after each addition.

Constraints
1≤x≤109
1≤n≤2⋅105
0<pi<x
Example

Input:
8 3
3 6 2

Output:
5 3 3
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int dist,n;
	cin >> dist >> n;
	multiset<int> mset;
	set<pii> st;
	st.insert({dist,0});
	mset.insert(dist);
	for(int i=0;i<n;i++){
		int pos;
		cin >> pos;
		auto it = st.upper_bound({pos,0});
		if(it!=st.end()){
			pii temp = *it;
			st.erase(it);
			int dis = temp.first - temp.second;
			auto it2 = mset.find(dis);
			mset.erase(it2);
			pii temp1 = {temp.first,pos};
			pii temp2 = {pos,temp.second};
			st.insert(temp1);
			mset.insert(temp1.first - temp1.second);
			st.insert(temp2);
			mset.insert(temp2.first - temp2.second);
		}
		auto it2 = mset.end();
		--it2;
		cout<<(*it2)<<" ";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	while(test--){
		solveQuestion();
	}
	return 0;
}