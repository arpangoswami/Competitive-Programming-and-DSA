#include <bits/stdc++.h>
using namespace std;
void allPossibleSums(int idx,int sumTillNow,int sum,const vector<int> &nums,set<vector<int> >&allSolutions,vector<int> &possibleSol){
    if(sumTillNow == sum){
        allSolutions.insert(possibleSol);
        return;
    }
    if(sumTillNow>sum){
        return;
    }
    for(;idx<nums.size() && sumTillNow+nums[idx]<=sum;idx++){
        possibleSol.push_back(nums[idx]);
        allPossibleSums(idx+1,sumTillNow+nums[idx],sum,nums,allSolutions,possibleSol);
        possibleSol.pop_back();
    }
}
int main(int argc,char const* argv[]){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int sum;
    cin>>sum;
    sort(nums.begin(),nums.end());
    vector<int> possibleSol;
    set<vector<int> >allSolutions;
    allPossibleSums(0,0,sum,nums,allSolutions,possibleSol);
    for(auto x = allSolutions.begin();x!=allSolutions.end();x++){
        for(int y: *x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
