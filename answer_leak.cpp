#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int check(const vector<int>&possibleAnswers,const vector<vector<int> >&answers,int n,int k){
    int correct = n+1;
    for(int j=0;j<k;j++){
        int c = 0;
        for(int i=0;i<n;i++){
            if(possibleAnswers[i] == answers[i][j]){
                c++;
            }
        }
        correct = min(c,correct);
    }
    return correct;
}
int allPossibleAnswerSheets(int idx,int n,int m,int k,const vector<vector<int> > &answers,int maxi,vector<int> &chefsAnswers,vector<int> possibleAnswers){
    if(idx==n){
        int c = check(possibleAnswers,answers,n,k);
        if(c>maxi){
            chefsAnswers = possibleAnswers;
        }
        return c;
    }
    for(int i=1;i<=m;i++){
        int temp = i;
        possibleAnswers.push_back(temp);
        allPossibleAnswerSheets(idx+1,n,m,k,answers,maxi,chefsAnswers,possibleAnswers);
    }
    //return 0;
}
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test;
    cin>>test;
    while(test--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<int> >answers;
        for(int i=0;i<n;i++){
            vector<int> temp(k,0);
            for(int j=0;j<k;j++){
                cin>>temp[j];
            }
            answers.push_back(temp);
        }
        int maxi = 0;
        vector<int> chefsAnswers;
        vector<int> possibleAnswers;
        int correct = 0;
        int a = 0;
        for(int i=0;i<(n*m);i++)
            a=max(a,allPossibleAnswerSheets(0,n,m,k,answers,maxi,chefsAnswers,possibleAnswers));
        for(int i=0;i<n;i++){
            cout<<chefsAnswers[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
