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
struct Connection{
	string firstTown;
	string secondTown;
	int cost;
	Connection(){
		firstTown = "Kolkata";
		secondTown = "Howrah";
		cost = 0;
	}
	Connection(string A,string B,int cst){
		firstTown = A;
		secondTown = B;
		cost = cst;
	}
};
string findPar(string town,map<string,string> &parent){
	if(parent[town] == town){
		return town;
	}
	string par = findPar(parent[town],parent);
	parent[town] = par;
	return par;
}
void unite(string town1,string town2,map<string,string> &parent,map<string,int> &ranks){
	string par1 = findPar(town1,parent),par2 = findPar(town2,parent);
	if(par1 == par2){
		return;
	}
	if(ranks[par1] < ranks[par2]){
		parent[par1] = par2;
	}else if(ranks[par1] > ranks[par2]){
		parent[par2] = par1;
	}else{
		parent[par2] = par1;
		ranks[par1]++;
	}
}
vector<Connection> minimumCostConnection(int num,vector<Connection> connection){
	map<string,string> parent;
	map<string,int> ranks;
	for(Connection c:connection){
		parent[c.firstTown] = c.firstTown;
		parent[c.secondTown] = c.secondTown;
		ranks[c.firstTown] = 0;
		ranks[c.secondTown] = 0;
	}
	if(connection.size() < (int)parent.size() - 1){
		return {};
	}
	sort(connection.begin(),connection.end(),[](auto &it1,auto &it2){
		return it1.cost <= it2.cost;
	});
	vector<Connection> ans;
	int picked = 0;
	for(Connection c:connection){
		string firstTown = c.firstTown,secondTown = c.secondTown;
		if(findPar(firstTown,parent) == findPar(secondTown,parent)){
			continue;
		}
		picked++;
		unite(firstTown,secondTown,parent,ranks);
		ans.push_back(c);
		if(picked == (int)parent.size()-1){
			break;
		}
	}
	set<string> diffCities;
	for(auto it:parent){
		diffCities.insert(findPar(it.first,parent));
		if(diffCities.size() > 1){
			return {};
		}
	}
	return ans;
}

int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	vector<Connection> v;
	v.push_back(Connection("townA","townB",1));
	v.push_back(Connection("townB","townC",4));
	v.push_back(Connection("townB","townD",5));
	v.push_back(Connection("townD","townE",5));
	// v.push_back(Connection("C","E",1));
	vector<Connection> ans = minimumCostConnection(5,v);
	for(auto it:ans){
		cout<<it.firstTown<<" "<<it.secondTown<<" "<<it.cost<<"\n";
	}
	return 0;
}