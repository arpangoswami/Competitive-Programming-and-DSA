#include<bits/stdc++.h>
using namespace std;
int piyushWalk(char **grid,int m,int n,int minS,int startS){
    int i = 0;
    while(i<m){
        bool flag = false;
        for(int j = 0;j<(n-1);j++){
            if(grid[i][j] == '.'){
                startS-=3;
                if(startS<=minS){
                    return -1;
                }
            }
            else if(grid[i][j] == '*'){
                startS+=4;
            }
            else if(grid[i][j] == '#'){
                flag = true;
                break;
            }
        }
        if(!flag){
            if(grid[i][n-1] == '.'){
                startS-=2;
                if(startS<=minS){
                    return -1;
                }
            }
            else if(grid[i][n-1] == '*'){
                startS+=5;
            }
        }
        i++;
    }
    return startS;
}
int main(){
    int rows,cols,min_strength,start;
    cin>>rows>>cols>>min_strength>>start;
    char **grid = new char *[rows];
    for(int i=0;i<rows;i++){
        grid[i] = new char [cols];
        for(int j = 0;j<cols;j++){
            cin>>grid[i][j];
        }
    }
    int strength = piyushWalk(grid,rows,cols,min_strength,start);
    if(strength<0){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
        cout<<strength<<endl;
    }
    for(int i=0;i<rows;i++){
        delete []grid[i];
    }
    delete []grid;
    return 0;
}
