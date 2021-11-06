/*
C. Uncle Bogdan and Country Happiness
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Uncle Bogdan is in captain Flint's crew for a long time and sometimes gets nostalgic for his homeland. Today he told you how his country introduced a happiness index.

There are n cities and n−1 undirected roads connecting pairs of cities. Citizens of any city can reach any other city traveling by these roads. Cities are numbered from 1 to n and the city 1 is a capital. In other words, the country has a tree structure.

There are m citizens living in the country. A pi people live in the i-th city but all of them are working in the capital. At evening all citizens return to their home cities using the shortest paths.

Every person has its own mood: somebody leaves his workplace in good mood but somebody are already in bad mood. Moreover any person can ruin his mood on the way to the hometown. If person is in bad mood he won't improve it.

Happiness detectors are installed in each city to monitor the happiness of each person who visits the city. The detector in the i-th city calculates a happiness index hi as the number of people in good mood minus the number of people in bad mood. Let's say for the simplicity that mood of a person doesn't change inside the city.

Happiness detector is still in development, so there is a probability of a mistake in judging a person's happiness. One late evening, when all citizens successfully returned home, the government asked uncle Bogdan (the best programmer of the country) to check the correctness of the collected happiness indexes.

Uncle Bogdan successfully solved the problem. Can you do the same?

More formally, You need to check: "Is it possible that, after all people return home, for each city i the happiness index will be equal exactly to hi".

Input
The first line contains a single integer t (1≤t≤10000) — the number of test cases.

The first line of each test case contains two integers n and m (1≤n≤105; 0≤m≤109) — the number of cities and citizens.

The second line of each test case contains n integers p1,p2,…,pn (0≤pi≤m; p1+p2+…+pn=m), where pi is the number of people living in the i-th city.

The third line contains n integers h1,h2,…,hn (−109≤hi≤109), where hi is the calculated happiness index of the i-th city.

Next n−1 lines contain description of the roads, one per line. Each line contains two integers xi and yi (1≤xi,yi≤n; xi≠yi), where xi and yi are cities connected by the i-th road.

It's guaranteed that the sum of n from all test cases doesn't exceed 2⋅105.

Output
For each test case, print YES, if the collected data is correct, or NO — otherwise. You can print characters in YES or NO in any case.

Examples
inputCopy
2
7 4
1 0 1 1 0 1 0
4 0 0 -1 0 -1 0
1 2
1 3
1 4
3 5
3 6
3 7
5 11
1 2 5 2 1
-11 -2 -6 -2 -1
1 2
1 3
1 4
3 5
outputCopy
YES
YES
inputCopy
2
4 4
1 1 1 1
4 1 -3 -1
1 2
1 3
1 4
3 13
3 3 7
13 1 4
1 2
1 3
outputCopy
NO
NO
Note
Let's look at the first test case of the first sample:


At first, all citizens are in the capital. Let's describe one of possible scenarios:

a person from city 1: he lives in the capital and is in good mood;
a person from city 4: he visited cities 1 and 4, his mood was ruined between cities 1 and 4;
a person from city 3: he visited cities 1 and 3 in good mood;
a person from city 6: he visited cities 1, 3 and 6, his mood was ruined between cities 1 and 3;
In total,
h1=4−0=4,
h2=0,
h3=1−1=0,
h4=0−1=−1,
h5=0,
h6=0−1=−1,
h7=0.
The second case of the first test:


All people have already started in bad mood in the capital — this is the only possible scenario.

The first case of the second test:


The second case of the second test:


It can be proven that there is no way to achieve given happiness indexes in both cases of the second test.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void dfs1(int v,int par,vector<int> adj_list[],bool &flag,vector<int> &population,vector<int> &happiness,vector<int> &subTreePop,vector<int> &subTreeGoodMood){
	subTreePop[v] = population[v];
	int happyAdd = 0;
	bool leaf = true;
	for(int x:adj_list[v]){
		if(x == par){
			continue;
		}
		leaf = false;
		dfs1(x,v,adj_list,flag,population,happiness,subTreePop,subTreeGoodMood);
		happyAdd += subTreeGoodMood[x];
		subTreePop[v] += subTreePop[x];
	}
	if((subTreePop[v] + happiness[v] + 2) % 2 == 1){
		flag = false;
	}
	int goodMood = (subTreePop[v] + happiness[v])/2;
	subTreeGoodMood[v] = goodMood;
	if(goodMood < 0 || goodMood > subTreePop[v]){
		flag = false;
	}
	if(happyAdd > subTreeGoodMood[v]){
		flag = false;
	}
}
void solveQuestion(){
	int n,pop;
	cin >> n >> pop;
	vector<int> population(n+1);
	vector<int> happiness(n+1);
	for(int i=1;i<=n;i++){
		cin >> population[i];
	}
	for(int i=1;i<=n;i++){
		cin >> happiness[i];
	}
	vector<int> adj_list[n+1];
	vector<int> subTreePop(n+1);
	vector<int> subTreeGoodMood(n+1);
	for(int i=0;i<(n-1);i++){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	bool flag = true;
	dfs1(1,0,adj_list,flag,population,happiness,subTreePop,subTreeGoodMood);
	if(!flag){
		cout<<"NO"<<"\n";
	}else{
		cout<<"YES"<<"\n";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}