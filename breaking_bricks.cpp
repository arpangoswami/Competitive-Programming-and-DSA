#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;
    cin>>t;
    while(t--){
        int s,w[3],hits = 1,temp,i=0;
        cin>>s>>w[0]>>w[1]>>w[2];
        temp = s;
        while(i<3){
            if(w[i]<=temp){
                temp-=w[i];
                i++;
            }
            else if(w[i]>temp){
                hits++;
                temp = s;
            }
        }
        cout<<hits<<endl;
    }
}
