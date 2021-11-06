#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
bool wordBreak(string &s,unordered_set<string> &wordDict,vector<string> &arrangement,vector<vector<string>> &sol,int i,int n){
    if(wordDict.count(s.substr(i))){
        arrangement.push_back(s.substr(i));
        sol.push_back(arrangement);
        arrangement.pop_back();
    }
    if(i == n){
        return false;
    }
    for(int k=i;k<n;++k){
        if(wordDict.count(s.substr(i,k-i+1))){
            arrangement.push_back(s.substr(i,k-i+1));
            bool f = wordBreak(s,wordDict,arrangement,sol,k+1,n);
            if(f){
                return true;
            }
            arrangement.pop_back();
        }
    }
    return false;
}
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    while(test--){
        int num_strings;
        cin>>num_strings;
        unordered_set<string> wordDict(num_strings);
        for(int i=0;i<num_strings;++i){
            string sr;
            cin>>sr;
            wordDict.insert(sr);
        } 
        string s;
        cin>>s;
        vector<vector<string>>solution;
        vector<string>arrangement;
        wordBreak(s,wordDict,arrangement,solution,0,s.size());
        vector<string> actual(solution.size());
        for(int i=0;i<solution.size();++i){
            actual[i]="";
            for(int j=0;j<solution[i].size();++j){
                actual[i]+=solution[i][j];
                if(j!=solution[i].size()-1){
                    actual[i]+=" ";
                }
            }
        }
        sort(actual.begin(),actual.end());
        for(int i=0;i<actual.size();++i){
            cout<<"("<<actual[i]<<")";
        }
        cout<<"\n";
    }
    return 0;
}