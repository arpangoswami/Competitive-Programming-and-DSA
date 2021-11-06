#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int cnt = 0;
        char x,y,c,d;
        bool flag = true;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i] && cnt==0){
                cnt++;
                x = a[i];
                y = b[i];
            }
            else if(a[i]!=b[i] && cnt==1){
                cnt++;
                c = a[i];
                d = b[i];
            }
            else if(a[i]!=b[i]){
                cnt++;
            }
            if(cnt == 2){
                if(x!=c || y!=d){
                    flag = false;
                    break;
                }
            }
            else if(cnt == 3){
                //cout<<"present1"<<endl;
                flag = false;
                break;
            }
        }
        if(cnt==0 || cnt==1){
            cout<<"No"<<endl;
            continue;
        }
        if(flag){
            cout<<"Yes"<<endl;
        }
        else if(!flag){
            cout<<"No"<<endl;
        }
    }
}
