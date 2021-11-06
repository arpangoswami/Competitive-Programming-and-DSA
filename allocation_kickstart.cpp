#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const* argv[]){
    int test;
    cin>>test;
    for(int x = 1;x<=test;x++){
        int n,budget;
        cin>>n>>budget;
        vector<int> houses(n);
        for(int i=0;i<n;i++){
            cin>>houses[i];
        }
        int ans = 0;
        sort(houses.begin(),houses.end());
        for(int i=0;i<n;i++){
            if(budget>=houses[i]){
                //cout<<"yoo"<<endl;
                ans++;
                budget-=houses[i];
            }
        }
        cout<<"Case #"<<x<<": "<<ans<<endl;
    }
    return 0;
}