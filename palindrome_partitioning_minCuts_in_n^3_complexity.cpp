#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int dp[1001][1001];
bool checkPalindrome(string &s,int i,int j){
    int low = i,high = j;
    while(low<high){
        if(s[low++]!=s[high--]){
            return false;
        }
    }
    return true;
}
int minPartition(string &s,int i,int j){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    else if(i>=j){
        dp[i][j] = 0;
    }
    else if(checkPalindrome(s,i,j)){
        dp[i][j] = 0;
    }
    else{
        dp[i][j] = INT_MAX;
        for(int k=i;k<j;k++){
            dp[i][j] = min(dp[i][j],1+minPartition(s,i,k)+minPartition(s,k+1,j));
        }
    }
    return dp[i][j];
    
}
int main() {
	int test;
	cin>>test;
	while(test--){
	    string s;
	    cin>>s;
	    memset(dp,-1,sizeof(dp));
	    cout<<minPartition(s,0,s.size()-1)<<endl;
	}
	return 0;
}