// { Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> &arr, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
    }
    cout << "\n";
}

void nearest(vector<vector<int>> &arr, int row, int col);
int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int row, col;
        cin >> row >> col;

        // Input matrix is represented using vectors of vectors
        vector<vector<int>> graph(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> graph[i][j];
            }
        }

        nearest(graph, row, col);
    }

    return 0;
}
// } Driver Code Ends


/*  Function to find the distance of nearest cell having 1
*   arr: vector of vectors to represent graph
*   row, col: rows and cols in given matrix
*/
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
typedef pair<int,int> pii;
bool isSafe(int x,int y,int row,int col,vector<vector<bool>> &visited){
    return ((x>=0) && (y>=0) && (x<row) && (y<col) && (!visited[x][y]));
}
void nearest(vector<vector<int>> &arr, int row, int col) {
    vector<vector<int>> distance(row,vector<int>(col,INT_MAX));
    vector<vector<bool>> visited(row,vector<bool>(col,false));
    queue<pii> q;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j] == 1){
                //cout<<"i: "<<i<<"j: "<<j<<endl;
                visited[i][j] = true;
                q.push({i,j});
            }
        }
    }
    q.push({-1,-1});
    int dist = 0;
    while(!q.empty()){
        pii p = q.front();
        q.pop();
        int x = p.first,y = p.second;
        //cout<<"x: "<<x<<"y: "<<y<<endl;
        if(x == -1 && y == -1){
            if(!q.empty()){
                q.push({-1,-1});
                dist++;
            }else{
                break;
            }
        }else{
            distance[x][y] = dist;
            for(int idx=0;idx<4;idx++){
                int newX = x+dx[idx],newY = y+dy[idx];
                if(isSafe(newX,newY,row,col,visited)){
                    visited[newX][newY] = true;
                    q.push({newX,newY});
                    //arr[newX][newY] = 1;
                }
            }
        }
    }
    print(distance,row,col);
}