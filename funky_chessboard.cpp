#include<bits/stdc++.h>
using namespace std;
int rows[8] = {-1,-2,-2,-1,1,2,2,1};
int cols[8] = {-2,-1,1,2,2,1,-1,-2};
bool isSafe(int i,int j,int n,int **grid,bool **visited){
    return ((i>=0) && (j>=0) && (i<n) && (j<n) && grid[i][j] == 1 && !visited[i][j]);
}
int knightTour(int i,int j,int n,int** grid,bool** visited){
    visited[i][j] = true;
    int ans = 0;
    for(int x = 0;x < 8;x++){
        if(isSafe(i+rows[x],j+cols[x],n,grid,visited)){
            ans = max(knightTour(i+rows[x],j+cols[x],n,grid,visited),ans);
        }
    }
    visited[i][j] = false;
    return ans + 1;
}
int main(int argc,char const* argv[]){
    int n;
    cin>>n;
    int **grid = new int* [n];
    bool **visited = new bool* [n];
    int ct = 0;
    for(int i=0;i<n;i++){
        grid[i] = new int[n];
        visited[i] = new bool[n];
        for(int j=0;j<n;j++){
            visited[i][j] = false;
            cin>>grid[i][j];
            if(grid[i][j] == 1){
                ct++;
            }
        }
    }
    int squares = knightTour(0,0,n,grid,visited);
    cout<<ct - squares<<endl;
    for(int i=0;i<n;i++){
        delete []grid[i];
        delete []visited[i];
    }
    delete []grid;
    delete []visited;
    return 0;
}