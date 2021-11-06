#include<iostream>
using namespace std;
int main() {
	string s,p;
	cin>>s>>p;
    if(s == "" && p== ""){
        cout<<true<<endl;
    }
    if(p == ""){
        cout<<false<<endl;
    }
	else{
        int idx = 0;
        bool star = false;
        for(unsigned i=0;i<p.size();i++){
            if(p[i]!='*'){
                p[idx++] = p[i];
                star = false;
            }
            else if(star == false && p[i] == '*'){
                p[idx++] = p[i];
                star = true;
            }
        }
        p = p.substr(0,idx);
        int m = s.size(),n = p.size();
        bool dp[m+1][n+1];
        for(int i=1;i<=m;i++){
            dp[i][0] = false;
        }
        dp[0][0] = true;
        if(p[0] == '*'){
            dp[0][1] = true;
        }
        else{
            dp[0][1] = false;
        }
        for(int j=2;j<=n;j++){
            dp[0][j] = false;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else if(p[j-1]!=s[i-1]){
                    dp[i][j] = false;
                }
            }
        }
        cout<<dp[m][n];
	}
	return 0;
}