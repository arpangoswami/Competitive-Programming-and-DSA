#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(vector<vector<int>> &A){
    int N = A.size();
    vector<vector<int>> solution;
    for(int len = 1;len<=N;len++){
        vector<int> temp;
        for(int i=0;i<len;i++){
            int j = len-1-i;
            temp.push_back(A[i][j]);
        }
        solution.push_back(temp);
    }
    for(int len = N-1;len>=1;len--){
        vector<int> temp;
        for(int j=N-1;j>=(N-len);j--){
            int i = 2*N - len - 1 - j;
            temp.push_back(A[i][j]);
        }
        solution.push_back(temp);
    }
    for(auto x:solution){
        for(auto a:x){
            cout<<a<<" ";
        }
        cout<<"\n";
    }
}
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    solve(arr);
    return 0;
}
    