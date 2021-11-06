/*
Rat Maze With Multiple Jumps Submissions: 2372   Accuracy: 22.11%   Difficulty: Medium   Marks: 4
Associated Course(s):   DSA- Online   Geeks Classes - Summers More
      
Problems
A Maze is given as N*N matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. Find the minimum number of Hops required for the rat to reach from the source block to the destination block. The number of steps rat can jump from (i, j) is represented by maze[i][j].

Note:
If multiple solutions exist, the shortest earliest hop will be accepted. For the same hop distance at any point, forward will be preferred over downward.
In the maze matrix, 0 means the block is the dead end and non-zero number means the block can be used in the path from source to destination. The non-zero value of mat[i][j] indicates number of maximum jumps rat can make from cell mat[i][j].

Input:
The first line of input contains an integer T denoting the number of test cases. For each test case, the first line contains an integer n denoting the size of the square matrix followed by N*N space-separated values of the matrix maze with each row in new line where 0's represents blocked paths and any number represents valid paths. 

Output:
For each test case, the output is a matrix containing 1 for the path taken and 0 for not chosen path. If no path exists print -1. For output matrix you need to just call print() which contains two arguments first size of solution or ouptut matrix and second is output matrix otherwise print "-1".

User task:
You don't need to read input or print anything. Your task is to complete the function solve() which takes the Maze and its dimensions N as inputs and prints the valid path if it exists. If it does not exist, print -1. 

Expected Time Complexity: O(NN).
Expected Auxiliary Space: O(N) if we don't consider the solution matrix for this.

Constraints:
1 <= T <= 50
2 <= n <= 50
0 <= maze[i][j] <= 20

Example:
Input
2
4 
2 1 0 0
3 0 0 1
0 1 0 1
0 0 0 1
4
2 1 0 0
2 0 0 1
0 1 0 1
0 0 0 1

Output:
1 0 0 0
1 0 0 1
0 0 0 1
0 0 0 1
-1

Explanation:
Testcase 1:  Rat started with m[0][0] and can jump up to 2 steps right/down. First check m[0][1] as it is 1, next check m[0][2], this won't lead to the solution. Then check m[1][0], as this is 3(non-zero), so we can make 3 jumps to reach m[1][3]. From m[1][3] we can move downwards taking 1 jump each time to reach destination at m[3][3].

Testcase 2: As no path exists, so -1.  
 

** For More Input/Output Examples Use 'Expected Output' option **
*/

#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends

bool isSafe(int i,int j,int N,vector<vector<bool>> &visited){
    return ((i>=0) && (j>=0) && (i<N) && (j<N) && !visited[i][j]);
}
bool ratInMaze(int i,int j,int N,int steps,vector<vector<bool>> &sol,vector<vector<bool>> &visited,vector<int> maze[],int &ct){
    if(i == N-1 && j == N-1){
        visited[i][j] = true;
        if(steps < ct){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    sol[i][j] = visited[i][j];
                }
            }
            ct = steps;
        }
        visited[i][j] = false;
        return false;
    }
    visited[i][j] = true;
    int max_steps = maze[i][j];
    for(int k=1;k<=max_steps;k++){
        if(isSafe(i,j+k,N,visited)){
            bool f = ratInMaze(i,j+k,N,steps+1,sol,visited,maze,ct);
            if(f){
                return f;
            }
        }
    }
    for(int k=1;k<=max_steps;k++){
        if(isSafe(i+k,j,N,visited)){
            bool f = ratInMaze(i+k,j,N,steps+1,sol,visited,maze,ct);
            if(f){
                return f;
            }
        }
    }
    visited[i][j] = false;
    return false;
}


void solve(int N, vector<int> maze[]) {
    // write code here
    vector<vector<bool>> visited(N,vector<bool>(N,false));
    vector<vector<bool>> sol(N,vector<bool>(N,false));
    int ct = N*N + 5;
    ratInMaze(0,0,N,1,sol,visited,maze,ct);
    if(ct == N*N + 5){
        cout<<-1<<"\n";
    }else{
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}