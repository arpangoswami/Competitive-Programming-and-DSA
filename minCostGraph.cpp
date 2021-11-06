#include <iostream>
#define MAX 100000000
using namespace std;
bool dfsSearch(int startX,int startY,const int &endX,const int &endY,int **mat,bool **vis,int tillNow){
    vis[startX][startY] = true;
    if(startX==endX && startY==endY){
        return tillNow;
    }
    /*if((mat[startX+1][startY] == 0 || vis[startX+1][startY] == true)&&(mat[startX-1][startY] == 0 || vis[startX-1][startY] == true)
       &&(mat[startX][startY+1] == 0 || vis[startX][startY+1] == true)&& (mat[startX][startY-1] == 0 || vis[startX][startY-1] == true)){
        return false;
    }*/
    int cost1 = MAX,cost2 = MAX,cost3 = MAX,cost4 = MAX;
    cost1 = dfsSearch(startX+1,startY,endX,endY,mat,vis,tillNow+mat[startX][startY]);
    cost2 = dfsSearch(startX-1,startY,endX,endY,mat,vis,tillNow+mat[startX][startY]);
    cost3 = dfsSearch(startX,startY-1,endX,endY,mat,vis,tillNow+mat[startX][startY]);
    cost4 = dfsSearch(startX,startY+1,endX,endY,mat,vis,tillNow+mat[startX][startY]);
    return min(cost1,min(cost2,min(cost3,cost4)));
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
	                mat[i][j] = MAX;
	            }
	            else{
	                cin>>mat[i][j];
	            }
	        }
	    }
	    int cost = dfsSearch(1,1,n,n,mat,vis,0);
	    cout<<cost<<endl;
	    for(int i=0;i<=n;i++){
	        delete []mat[i];
	        delete []vis[i];
	    }
	    delete []mat;
	    delete []vis;
	}
	return 0;
}
