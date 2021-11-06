#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
class dsu{
public: 
	vector<int> parent;
	vector<int> rank;
	int n;
	dsu(int _n): n(_n){
		parent.resize(n+1);
		rank.resize(n+1);
		for(int i=0;i<=n;i++){
			parent[i] = i;
			rank[i] = 0;
		}
	}
	int findPar(int x){
		if(x == parent[x]){
			return x;
		}
		int v = findPar(parent[x]);
		parent[x] = v;
		return v;
	}
	void unite(int x,int y){
		int x_rep = findPar(x),y_rep = findPar(y);
		if(x_rep == y_rep){
			return;
		}
		if(rank[x_rep] > rank[y_rep]){
			parent[y_rep] = x_rep;
		}else if(rank[x_rep] < rank[y_rep]){
			parent[x_rep] = y_rep;
		}else{
			parent[y_rep] = x_rep;
			rank[x_rep]++;
		}
	}
};
int getPowerCouple2021(int friends,int friend_edges,vector<int> friends_from,vector<int> friends_to,vector<int> friends_weight){
	map<int,vector<pii> > mp;
	for(int i=0;i<friend_edges;i++){
		mp[friends_weight[i]].push_back({friends_from[i],friends_to[i]});
	}
	map<int,set<int>> peopleCorrespondingInterest;
	for(auto it:mp){
		int interest = it.first;
		dsu d(friends);
		for(auto edges:it.second){
			d.unite(edges.first,edges.second);
		}
		set<int> notSelfParent;
		for(int i=1;i<=friends;i++){
			if(d.findPar(i) != i){
				notSelfParent.insert(d.findPar(i));
			}
		}
		for(int i=1;i<=friends;i++){
			if(notSelfParent.count(d.findPar(i))){
				peopleCorrespondingInterest[i].insert(interest);
			}
		}
	}
	int maxSize = 0;
	int maxProd = 0;
	for(int i=1;i<=friends;i++){
		for(int j=i+1;j<=friends;j++){
			int interestSize = 0;
			for(int x:peopleCorrespondingInterest[i]){
				if(peopleCorrespondingInterest[j].count(x)){
					interestSize++;
				}
			}
			if((interestSize > maxSize) || (interestSize == maxSize && i*j > maxProd)){
				maxSize = interestSize;
				maxProd = i*j;
			}
		}
	}
	return maxProd;
}
int main(){
	// int friends = 4;
	// int friend_edges = 5;
	// vector<int> friends_from = {1,1,2,2,2};
	// vector<int> friends_to = {2,2,3,3,4};
	// vector<int> friends_weight =  {2,3,1,3,4};
	// cout<<getPowerCouple2021(friends,friend_edges,friends_from,friends_to,friends_weight);
	// int friends = 4;
	// int friend_edges = 5;
	// vector<int> friends_from = {1,1,2,2,2};
	// vector<int> friends_to = {2,2,3,3,4};
	// vector<int> friends_weight =  {1,2,1,3,3};
	// cout<<getPowerCouple2021(friends,friend_edges,friends_from,friends_to,friends_weight);
	int friends = 4;
	int friend_edges = 4;
	vector<int> friends_from = {1,1,2,2};
	vector<int> friends_to = {3,3,4,4};
	vector<int> friends_weight =  {1,2,1,2};
	cout<<getPowerCouple2021(friends,friend_edges,friends_from,friends_to,friends_weight);
	return 0;
}