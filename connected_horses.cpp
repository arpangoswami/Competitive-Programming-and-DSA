/*
Connected horses
Send Feedback
You all must be familiar with the chess-board having
8*8 squares of alternate black and white cells. Well, here
we have for you a similar
N*M size board with similar arrangement of black and white
cells.
A few of these cells have Horses placed over them.
Each horse is unique. Now these horses are not the
usual horses which could jump to any of the
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo
10^9+7
Input:
First line contains
T which is the number of test cases.
T test cases follow first line of each containing three integers
N, M and Q where
N,M is the size of the board and
Q is the number of horses on it.

Q lines follow each containing the 2 integers
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
SAMPLE OUTPUT
4
2
*/
#include<bits/stdc++.h>
using namespace std;
long long const mod = 1e9+7;
long long factorials[1000001];
int rows[8] = {-1,-2,-2,-1,1,2,2,1};
int cols[8] = {-2,-1,1,2,2,1,-1,-2};
bool isSafe(int i,int j,int n,int m,bool **grid,bool **visited){
    return ((i>=0) && (j>=0) && (i<n) && (j<m) && (grid[i][j]) && (!visited[i][j]));
}
void fact(){
	factorials[0] = 1;
    for(int i=1;i<=1000000;++i){
        factorials[i] = (factorials[i-1]%mod*i%mod)%mod;
    }
}
int DFS(int i,int j,int n,int m,bool **grid,bool **visited){
    int ans = 1;
    visited[i][j] = true;
    for(int x=0;x<8;x++){
        if(isSafe(i+rows[x],j+cols[x],n,m,grid,visited)){
            ans+=DFS(i+rows[x],j+cols[x],n,m,grid,visited);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact();
    int test;
    cin>>test;
    while(test--){
        int n,m,q;
        cin>>n>>m>>q;
        bool **grid = new bool *[n];
        bool **visited = new bool *[n];
        for(int i=0;i<n;i++){
            grid[i] = new bool[m]();
            visited[i] = new bool[m]();
        }
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            grid[x-1][y-1] = true;
        }
        long long ans = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !visited[i][j]){
                    int ct = DFS(i,j,n,m,grid,visited);
                    ans = (ans%mod * factorials[ct]%mod)%mod;
                }
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<n;i++){
            delete []grid[i];
            delete []visited[i];
        }
        delete []grid;
        delete []visited;
    }
	return 0;
}
