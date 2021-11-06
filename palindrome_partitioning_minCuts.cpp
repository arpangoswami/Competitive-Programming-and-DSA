#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int main() {
	//code
	int test;
	cin>>test;
	while(test--){
	    string s;
	    cin>>s;
	    int n = s.size();
	    int **dp = new int* [n];
	    bool **palIdx = new bool* [n];
	    for(int i=0;i<n;i++){
	        dp[i] = new int[n];
	        palIdx[i] = new bool[n]();
	        for(int j=0;j<n;j++){
	            dp[i][j] = -1;
	        }
	    }
	    for(int i=0;i<n;i++){
	        palIdx[i][i] = true;
	    }
	    for(int i=0;i<(n-1);i++){
	        if(s[i] == s[i+1]){
	            palIdx[i][i+1] = true;
	        }
	        else{
	            palIdx[i][i+1] = false;
	        }
	    }
	    for(int l=3;l<=n;l++){
	        for(int i=0;i<n-l+1;i++){
	            int j = i+l-1;
	            if(s[i] == s[j]){
	                palIdx[i][j] = palIdx[i+1][j-1];
	            }
	            else{
	                palIdx[i][j] = false;
	            }
	        }
	    }
	    int* solution = new int[n];
	    for(int i=0;i<n;i++){
	        if(palIdx[0][i]){
	            solution[i] = 0;
	        }
	        else{
	            int temp = 1e9;
    	        for(int j=0;j<i;j++){
    	            if((palIdx[j+1][i]) && temp>solution[j] + 1){
    	                temp = 1+solution[j];
    	            }
    	        }
    	        solution[i] = temp;   
	        }
	    }
	    cout<<solution[n-1]<<"\n";
	    for(int i=0;i<n;i++){
	        delete []palIdx[i];
	    }
	    delete []solution;
	    delete []palIdx;
	}
	return 0;
}