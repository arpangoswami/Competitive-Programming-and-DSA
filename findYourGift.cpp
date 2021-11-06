#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int x = 0,y = 0;
        bool xflag = false,yflag = false;
        if(s[0]=='L'){
            x--;
            xflag = true;
        }
        else if(s[0]=='R'){
            x++;
            xflag = true;
        }
        else if(s[0]=='U'){
            y++;
            yflag = true;
        }
        else{
            y--;
            yflag = true;
        }
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                if(s[i]=='L'){
                    if(xflag == false){
                        x--;
                        xflag = true;
                        yflag = false;
                    }
                }
                else if(s[i]=='R'){
                    if(xflag == false){
                        x++;
                        xflag = true;
                        yflag = false;
                    }
                }
                else if(s[i]=='U'){
                    if(yflag == false){
                        y++;
                        xflag = false;
                        yflag = true;
                    }
                }
                else if(s[i]=='D'){
                    if(yflag == false){
                        y--;
                        xflag = false;
                        yflag = true;
                    }
                }
            }
        }
        cout<<x<<" "<<y<<endl;
    }
}
