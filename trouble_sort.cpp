#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct element {
	int value;
	int bin;
};
int findParent(int x,vector<int> &parent){
	if(x == parent[x]){
		return x;
	}
	parent[x] = findParent(parent[x],parent);
	return parent[x];
}
void unionRank(int x,int y,vector<int> &parent,vector<int> &rank){
	int x_rep = findParent(x,parent),y_rep = findParent(y,parent);
	if(x_rep == y_rep){
		return;
	}
	if(rank[x_rep]>rank[y_rep]){
		parent[y_rep] = x_rep;
	}else if(rank[y_rep]>rank[x_rep]){
		parent[x_rep] = y_rep;
	}else{
		parent[y_rep] = x_rep;
		rank[x_rep]++;
	}
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		vector<element> toSort(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			toSort[i].value = arr[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> toSort[i].bin;
		}
		vector<int> parent(n);
		vector<int> rank(n);
		for(int i=0;i<n;i++){
			parent[i] = i;
			rank[i] = 0;
		}
		sort(arr.begin(),arr.end());
		unordered_set<int> s1;
		unordered_set<int> s0;
		for(int i=0;i<n;i++){
			if(toSort[i].bin == 0){
				s0.insert(i);
			}else{
				s1.insert(i);
			}
		}
		for(int x:s0){
			for(int y:s1){
				unionRank(x,y,parent,rank);
			}
		}
		bool f = true;
		for(int i=0;i<n;i++){
			if(arr[i] == toSort[i].value){
				continue;
			}
			bool needToSwap = true;
			int lb = lower_bound(arr.begin(),arr.end(),toSort[i].value) - arr.begin();
			auto itr = upper_bound(arr.begin(),arr.end(),toSort[i].value);
			itr = prev(itr);
			int rb = itr - arr.begin();
			for(int idx=lb;idx<=rb;idx++){
				if(findParent(i,parent) == findParent(idx,parent)){
					needToSwap = false;
					break;
				}
			}
			if(needToSwap){
				f = false;
				break;
			}
		}
		if(f){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}