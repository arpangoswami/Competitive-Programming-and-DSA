#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        vector<string>board(9);
        for(int i=0;i<9;i++){
            cin>>board[i];
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '1'){
                    board[i][j] = '2';
                }
            }
        }
        for(int i=0;i<9;i++){
            cout<<board[i]<<endl;
        }
    }
    return 0;
}
