#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    typedef pair<int,int> pii;
    int n;
    cin>>n;
    map<pii,string> mp;
    for(int i=0;i<n;i++){
        string s;
        pii p;
        cin>>p.first>>p.second>>s;
        mp[p] = s;
    }
    int q;
    cin>>q;
    while(q--){
        pii code;
        cin>>code.first>>code.second;
        cout<<mp[code]<<"\n";
    }
    return 0;
}