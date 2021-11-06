#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int row[4] = {-1,0,0,1};
int cols[4] = {0,-1,1,0};
bool isSafe(int i,int j,int m,int n,int **arr,int color,bool **visited){
	return ((i>=0) && (j>=0) && (i<m) && (j<n) && arr[i][j] == color && !visited[i][j]);
}
void floodFill(int **arr,bool **visited,int i,int j,int m,int n,int col,int color){
	visited[i][j] = true;
	arr[i][j] = color;
	for(int x=0;x<4;x++){
		if(isSafe(i+row[x],j+cols[x],m,n,arr,col,visited)){
			floodFill(arr,visited,i+row[x],j+cols[x],m,n,col,color);
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int m,n;
		cin>>m>>n;
		int **arr = new int* [m];
		bool **visited = new bool* [m];
		for(int i=0;i<m;i++){
			arr[i] = new int[n];
			visited[i] = new bool[n];
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
				visited[i][j] = false;
			}
		}
		int sx,sy,color;
		cin>>sx>>sy>>color;
		floodFill(arr,visited,sx,sy,m,n,arr[sx][sy],color);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cout<<arr[i][j]<<" ";
			}
		}
		cout<<"\n";
		for(int i=0;i<m;i++){
			delete []arr[i];
			delete []visited[i];
		}		
		delete []arr;
		delete []visited;
	}
	return 0;
}