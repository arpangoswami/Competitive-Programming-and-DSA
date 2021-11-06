#include <bits/stdc++.h>
using namespace std;
bool isSafe(int i,int col,bool graph[101][101],int V,vector<int> &colors){
    for(int k=0;k<V;k++){
        if(graph[i][k] && colors[k] == col){
            return false;
        }
    }
    return true;
}
bool dfs(int i,int m,bool graph[101][101],int V,vector<int> &colors){
    if(i == V){
        return true;
    }
    for(int j=1;j<=m;j++){
        if(isSafe(i,j,graph,V,colors)){
            colors[i] = j;
            if(dfs(i+1,m,graph,V,colors)){
                return true;
            }
            colors[i] = -1;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V) {
    vector<int> colors(V,-1);
    return dfs(0,m,graph,V,colors);;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}