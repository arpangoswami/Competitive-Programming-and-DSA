/*
https://www.spoj.com/problems/AKBAR/
AKBAR - Akbar , The great
#graph #bfs #dfs
 

All of us are familiar with the reign of the great mughal ruler , Akbar. He was always concerned with the prosperity and safety of the people . Therefore to safeguard his kingdom (which consisted of N cities) he wanted to place secret soldiers all over his kingdom so as to protect the people . But since his kingdom is very large therefore he wanted to place as minimum of them as possible because the salary of these undercover soldiers was very high ,ie, in such a way that every city is protected by only one soldier . As for these soldiers , they have varible strength .The strength of a particular soldier is defined as the number of cities he can safeguard from a particular city along with that city. Also the kingdom is connected with a network of secret two way roads for faster access only accessible to these soldiers. The length of any road on this network between any two cities is 1 kms .There are R such roads in the kingdom. He had given this task to birbal to place the soldiers . Birbal didn't wanted to be a fool in front of the king , therefore took the job and placed M soldiers all over the kingdom but he was not very good at mathematics . But since he is very intelligent he somehow places the guards all over the kingdom and now turns to you (who is a genius mathematician ;) ) to check whether his placements are good or not.Your task is to check if all the placements of the soldiers are optimum or not.INPUTThe input consists of t test cases . Each test case then consists of 3 parts.The first line consists of N and R and M.the next R lines consists of two numbers a and b denoting the two cities between which a road exists .the next M lines consists of 2 numbers k and strength denoting the city number and the strength of that particular soldier respectively .=> strength 0 means it will only guard the city on which it is present .=> assume every city is accesible from every other city .CONSTRAINTS t <= 10; 1 <= N <= 10^6; N-1 <= R <= min(10^9 , (N*(N-1))/2)); 1 <= k <= N; 0 <= strength <= 10^6OUTPUTprint "Yes" if the soldiers are placed optimumly else print "No". (quotes are for clearity)SAMPLE INPUT2 3 2 21 22 31 22 04 5 21 41 21 34 23 42 13 0SAMPLE OUTPUTNoYesWARNING ==> Large input . Be careful with certain languages. Use scanf() for c/c++ ;
All of us are familiar with the reign of the great mughal ruler , Akbar. He was always concerned with the prosperity and safety of the people . Therefore to safeguard his kingdom (which consisted of N cities) he wanted to place secret soldiers all over his kingdom so as to protect the people . But since his kingdom is very large therefore he wanted to place them in such a way that every city is protected by one and only one soldier.According to Akbar , this is the optimum placement.

 As for these soldiers they can protect multiple cities according to their strengths.

The strength of a particular soldier is defined as the maximum distance upto which a guard can protect a city from its base city(base city is the city assigned to the guard). If there are 3 cities C1, C2 and C3 such that C1 C2 and C2 C3 are connected respectively, if a soldier with strength 1 is placed at C2 then all the cities C1, C2 and C3 are protected by that soldier.

Also the kingdom is connected with a network of secret two way roads for faster access only accessible to these soldiers. The length of any road on this network between any two cities is 1 kms .There are R such roads in the kingdom. 

He had given this task to birbal to place the soldiers . Birbal didn't wanted to be a fool in front of the king , therefore took the job and placed M soldiers all over the kingdom but he was not very good at mathematics . But since he is very intelligent he somehow places the guards all over the kingdom and now turns to you (who is a genius mathematician ;) ) to check whether his placements are good or not.

 

Your task is to check if the placements of the soldiers are optimum or not.

 

INPUT

 

The input consists of T test cases . Each test case then consists of 3 parts.The first line consists of N, R and M.

the next R lines consists of two numbers A and B denoting the two cities between which a road exists .

the next M lines consists of 2 numbers, city number K and strength S of that particular soldier.

 

=> strength 0 means it will only guard the city on which it is present .

=> assume every city is accesible from every other city .

 

CONSTRAINTS

 

 T <= 10;

 1 <= N <= 10^6;

 N -1 <= R <= min( 10^7 , ( N * (N - 1) ) / 2) );

 1 <= K <= N;

 0 <= S <= 10^6

 

OUTPUT

 

print "Yes" if the soldiers are placed optimumly else print "No". (quotes are for clarity)

 

SAMPLE INPUT

 

2

3 2 2

1 2

2 3

1 2

2 0

4 5 2

1 4

1 2

1 3

4 2

3 4

2 1

3 0

 

SAMPLE OUTPUT

 

No

Yes

 

WARNING ==> Large input.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
struct node{
	int num;
	int strength;
	int guardedBy;
	node(){
		num = -1;
		strength = -1;
		guardedBy = -1;
	}
	node(int nm,int sg,int gb){
		num = nm;
		strength = sg;
		guardedBy = gb;
	}
};
bool solve(int n,vector<int> *adj_list,queue<node> &q,int *guarded){
	while(!q.empty()){
		node temp = q.front();
		q.pop();
		int sg = temp.strength,x = temp.num,gb = temp.guardedBy;
		for(int nb:adj_list[x]){
			if(guarded[nb] == gb){
				continue;
			}
			else if(guarded[nb]!=0){
				return false;
			}
			else{
				guarded[nb] = gb;
				if(sg > 1){
					q.push(node(nb,sg-1,gb));
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(guarded[i] == 0){
			return false;
		}
	}
	return true;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,r,m;
		cin>>n>>r>>m;
		vector<int> *adj_list = new vector<int>[n+1]();
		for(int i=0;i<r;i++){
			int u,v;
			cin>>u>>v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}
		bool flag = true;
		queue<node> q;
		int *guarded = new int[n+1]();
		for(int i=0;i<m;i++){
			int nm,sg;
			cin>>nm>>sg;
			if(guarded[nm]!=0){
				flag = false;
			}
			guarded[nm] = nm;
			if(sg > 0)
				q.push(node(nm,sg,nm));
		}
		if(!flag){
			cout<<"No"<<"\n";
		}
		flag = solve(n,adj_list,q,guarded);
		if(flag){
			cout<<"Yes"<<"\n";
		}
		else{
			cout<<"No"<<"\n";
		}
		delete []adj_list;
		delete []guarded;
	}
	return 0;
}