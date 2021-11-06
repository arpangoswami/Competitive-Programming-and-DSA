#include <bits/stdc++.h>
using namespace std;
const int SIZE = 8;
int rowKing, colKing, rowNinja, colNinja;
int knightdx[8] = { -1, -2, -2, -1, 1, 2, 2, 1};
int knightdy[8] = { -2, -1, 1, 2, 2, 1, -1, -2};
int dx[SIZE] = {0, 1, 1, 1, -1, -1, -1, 0};
int dy[SIZE] = {1, -1, 0, 1,-1, 0, 1, -1,};
bool withinBoard(int row, int col) {
    return (row >= 0 && col >= 0 && row < SIZE && col < SIZE);
}
bool bishopAttack(int row, int col) {
    //attacked by bishop power of ninja
    if((row - col) != (rowNinja - colNinja) && (row + col) != (rowNinja + colNinja)){
        return false;
    }
    if(row - col == rowNinja - colNinja && rowKing - colKing == row - col){
        if(((rowKing > row && colKing > col) && (rowKing < rowNinja && colKing < colNinja)) || 
            ((rowKing > rowNinja && colKing > colNinja) && (rowKing < row && colKing < col))){
            return false;
        }
    }
    if(row + col == rowNinja + colNinja && rowKing + colKing == row + col){
        if(((rowKing > row && colKing < col) && (rowKing < rowNinja && colKing > colNinja)) || 
            ((rowKing < row && colKing > col) && (rowKing > rowNinja && colKing < colNinja))){
            return false;
        }
    }
    return true;
}
bool rookAttack(int row, int col) {
    //attacked by rook power of ninja
    if(row != rowNinja && col != colNinja){
        return false;
    }
    if(row == rowNinja && row == rowKing){
        if((colKing > col && colKing < colNinja) || (colKing > colNinja && colKing < col)){
            return false;
        }
    }
    if(col == colNinja && col == colKing){
        if((rowKing > row && rowKing < rowNinja) || (rowKing > rowNinja && rowKing < row)){
            return false;
        }
    }
    return true;
}
bool knightAttack(int row, int col) {
    //attacked by knight power of ninja
    for (int k = 0; k < SIZE; k++) {
        if (withinBoard(rowNinja + knightdx[k], colNinja + knightdy[k])) {
            int nRow = rowNinja + knightdx[k];
            int nCol = colNinja + knightdy[k];
            if (row == nRow && col == nCol) {
                return true;
            }
        }
    }
    return false;
}
bool kingAttack(int row, int col) {
    //black king attacked by king
    if (abs(row - rowKing) > 1 || abs(col - colKing) > 1) {
        return false;
    }
    return true;
}
bool attack(int row, int col) {
    //black king is attacked by either king or ninja
    if (bishopAttack(row, col) || knightAttack(row, col) || rookAttack(row, col) || kingAttack(row, col)) {
        return true;
    }
    return false;
}
bool neighbourSafe(int row, int col) {
    for (int x = 0; x < SIZE; x++) {
        if (withinBoard(row + dx[x], col + dy[x])) {
            int nRow = row + dx[x];
            int nCol = col + dy[x];
            if(nRow == rowNinja && nCol == colNinja && !kingAttack(nRow,nCol)){
                //capture the ninja
                return true;
            }
            if (!attack(nRow, nCol)) {
                //not within range of both
                return true;
            }
            
        }
    }
    return false;
}

vector<int> ninjaChess2021(string king, string ninja) {
    rowKing = '8' - king[1], colKing = king[0] - 'a';
    rowNinja = '8' - ninja[1], colNinja = ninja[0] - 'a';
    vector<int> sol(4);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i == rowKing && j == colKing) || (i == rowNinja && j == colNinja)) {
                continue;
            }
            if (kingAttack(i, j)) {
                continue;
            }
            if (attack(i, j) && !neighbourSafe(i, j)) {
                sol[0]++;
            } else if (attack(i, j) && neighbourSafe(i, j)) {
                sol[1]++;
            } else if (!attack(i, j) && !neighbourSafe(i, j)) {
                sol[2]++;
            } else if (!attack(i, j) && neighbourSafe(i, j)) {
                sol[3]++;
            }
        }
    }
    return sol;
}

int main(){
    //vector<int> ans = ninjaChess2021("d3","e4");
    //vector<int> ans = ninjaChess2021("a1","g5");
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}