/*Monk and the Islands
Send Feedback
MONK AND THE ISLAND
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N
SAMPLE INPUT
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
SAMPLE OUTPUT
2
2*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int bfs(int finish,vector<int> *edges,vector<bool> &visited,vector<int> &distance){
    queue<int> q;
    q.push(0);
	distance[0] = 0;
	visited[0] = true;
    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        int dist = distance[vertex];
        for(unsigned i = 0;i<edges[vertex].size();i++){
            int x = edges[vertex][i];
            if(!visited[x]){
				visited[x] = true;
                q.push(x);
				distance[x] = dist+1;
            }
        }
    }
    return distance[finish];
}
int main(int argc,char const* argv[]){
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        vector<int> *edges = new vector<int> [n]();
		vector<bool> visited(n,false);
		vector<int> distance(n,-1);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            edges[u-1].push_back(v-1);
            edges[v-1].push_back(u-1);
        }
        cout<<bfs(n-1,edges,visited,distance)<<endl;
        delete []edges;
    }
    return 0;
}
