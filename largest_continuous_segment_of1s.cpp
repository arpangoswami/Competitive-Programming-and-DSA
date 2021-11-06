#include <bits/stdc++.h>
using namespace std;
bool isSafe(int **cake,int i,int j,int n,bool **visited){
    return ((i>=0) && (j>=0) && (i<n) && (j<n) && !visited[i][j] && cake[i][j]);
}
int rows[4] = {-1,0,0,1};
int colums[4] = {0,-1,1,0};
int DFS(int **cake,int i,int j,int n,bool **visited){
    visited[i][j] = true;
    int area = 1;
    for(int x=0;x<4;x++){
        if(isSafe(cake,i+rows[x],j+colums[x],n,visited)){
            area+=DFS(cake,i+rows[x],j+colums[x],n,visited);
        }
    }
    return area;
}
int main(int argc,char const* argv[]){
    int n;
    cin>>n;
    int **cake = new int *[n];
    bool **visited = new bool *[n];
    for(int i=0;i<n;i++){
        cake[i] = new int[n]();
        visited[i] = new bool[n]();
        for(int j=0;j<n;j++){
            cin>>cake[i][j];
        }
    }
    int maximum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j] == 1 && !visited[i][j]){
                int curr = DFS(cake,i,j,n,visited);
                maximum = max(curr,maximum);
            }
        }
    }
    for(int i=0;i<n;i++){
        delete []visited[i];
        delete []cake[i];
    }
    cout<<maximum<<endl;
    return 0;
}
