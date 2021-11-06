#include <iostream>
using namespace std;
bool dfsSearch(int startX,int startY,int **mat,bool **vis){
    vis[startX][startY] = true;
    if(mat[startX][startY] == 2){
        return true;
    }
    if((mat[startX+1][startY] == 0 || vis[startX+1][startY] == true)&&(mat[startX-1][startY] == 0 || vis[startX-1][startY] == true)
       &&(mat[startX][startY+1] == 0 || vis[startX][startY+1] == true)&& (mat[startX][startY-1] == 0 || vis[startX][startY-1] == true)){
        return false;
    }
    bool flag1 = false,flag2 = false,flag3 = false,flag4 = false;
    if(((mat[startX+1][startY] == 2)||(mat[startX+1][startY] == 3))&& (vis[startX+1][startY] == false)){
        flag1 = dfsSearch(startX+1,startY,mat,vis);
    }
    if(((mat[startX-1][startY] == 2)||(mat[startX-1][startY] == 3))&& (vis[startX-1][startY] == false)){
        flag2 = dfsSearch(startX-1,startY,mat,vis);
    }
    if(((mat[startX][startY-1] == 2)||(mat[startX][startY-1] == 3))&& (vis[startX][startY-1] == false)){
        flag3 = dfsSearch(startX,startY-1,mat,vis);
    }
    if(((mat[startX][startY+1] == 2)||(mat[startX][startY+1] == 3))&& (vis[startX][startY+1] == false)){
        flag4 = dfsSearch(startX,startY+1,mat,vis);
    }
    return (flag1 || flag2 || flag3 || flag4);
}
int main() {
	//code
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    int startX,startY;
	    int **mat = new int *[n+2];
	    bool **vis = new bool *[n+2];
	    for(int i=0;i<=(n+1);i++){
	        mat[i] = new int[n+2];
	        vis[i] = new bool[n+2]();
	    }
	    for(int i=0;i<=(n+1);i++){
	        for(int j=0;j<=(n+1);j++){
	            if(i==0 || j==0 || i==(n+1) || j==(n+1)){
	                mat[i][j] = 0;
	            }
	            else{
	                cin>>mat[i][j];
	                if(mat[i][j] == 1){
	                    startX = i;
	                    startY = j;
	                }
	            }
	        }
	    }
	    bool flag = dfsSearch(startX,startY,mat,vis);
	    cout<<flag<<endl;
	    for(int i=0;i<=n;i++){
	        delete []mat[i];
	        delete []vis[i];
	    }
	    delete []mat;
	    delete []vis;
	}
	return 0;
}
