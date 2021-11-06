#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod = 998244353;
int main(int argc,char const* argv[]){
    string s,t;
    cin>>s>>t;
    unordered_set<char> lettersT,lettersS;
    for(int i=0;i<t.size();i++){
        lettersT.insert(t[i]);
    }
    for(int i=0;i<s.size();i++){
        lettersS.insert(s[i]);
    }
    for(auto it = lettersT.begin();it!=lettersT.end();++it){
        if(lettersS.count(*it) == 0){
            cout<<0<<endl;
            break;
        }
    }
    
    return 0;
}