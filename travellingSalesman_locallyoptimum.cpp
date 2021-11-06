#include <bits/stdc++.h>
#include <cstdlib>
typedef pair<string,int> pii;
map<string,int> cityToInt;
map<int,string> intToCity;
int locallyOptimumTravellingSalesman(string currentCity,vector<pii> adj_list[],set<int> &visitedCities,string startcity,int numCities){
	cout<<currentCity<<"->";
	visitedCities.insert(cityToInt[currentCity]);
	if(visitedCities.size() == numCities){
		pathTaken += "->";
		pathTaken += startcity;
		for(pii x: adj_list[cityToInt[currentCity]]){
			if(x.first == startcity){
				return x.second;
			}
		} 
		return 0;
	}
	int minDist = 1e9;
	string minCity = "Moscow";
	for(pii x:adj_list[cityToInt[currentCity]]){
		if(visitedCities.count(cityToInt[x.first])){
			continue;
		}
		if(x.second < minDist){
			minDist = x.second;
			minCity = x.first;
		}
	}
	
	return minDist + locallyOptimumTravellingSalesman(minCity,adj_list,visitedCities,startcity,numCities);
}
void solveQuestion(){
	int n;
	cin >> n;
	pathTaken.clear();
	vector<pii> adj_list[n+1];
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		cityToInt[s] = i;
		intToCity[i] = s;
	}
	int edges = (n*(n-1))/2;
	for(int i=0;i<edges;i++){
		int distance;
		string x,y;
		cin >> x >> y >> distance;
		adj_list[cityToInt[x]].push_back({y,distance});
		adj_list[cityToInt[y]].push_back({x,distance});
	}
	string startcity;
	cin >> startcity;
	set<int> visitedCities;
	visitedCities.insert(cityToInt[startcity]);
	cout<<"Path taken was: \n";
	int totalDistance = locallyOptimumTravellingSalesman(startcity,adj_list,visitedCities,startcity,n);
	cout<<startcity<<"\n";
	cout<<"distance was :\n"<<totalDistance<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE

		freopen("input.txt", "r", stdin);

		freopen("output.txt", "w", stdout);

	#endif // ONLINE_JUDGE
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}