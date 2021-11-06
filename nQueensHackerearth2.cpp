#include<bits/stdc++.h>
using namespace std;
bool canPlace(int i,int j,bool **board,int n){
    for(int x = i-1;x>=0;x--){
        if(board[x][j] == true){
            return false;
        }
    }
    int x = i-1,y = j-1;
    while(x>=0 && y>=0){
        if(board[x][y] == true){
            return false;
        }
        x--;
        y--;
    }
    x = i-1,y = j+1;
    while(x>=0 && y<n){
        if(board[x][y] == true){
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool solveNQueens(int row,bool **board,int n){
    if(row == n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(canPlace(row,i,board,n)){
            board[row][i] = true;
            if(solveNQueens(row+1,board,n)){
                return true;
            }
            board[row][i] = false;
        }
    }
    return false;
}
int main(void){
    int n;
    cin>>n;
    bool **board = new bool *[n];
    for(int i=0;i<n;i++) board[i] = new bool [n]();
    bool flag = solveNQueens(0,board,n);
    if(flag){
        //cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"Not possible"<<endl;
    }
    for(int i=0;i<n;i++){
        delete []board[i];
    }
    delete []board;
}
