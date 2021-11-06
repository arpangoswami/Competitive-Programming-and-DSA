#include <bits/stdc++.h>
using namespace std;
bool solve(int x,int k){
    if(k>(int)log2(x)){
        return false;
    }
    int temp1 = x,temp2 = k;
    vector<int> factors;
    while(temp1%2 == 0){
        factors.push_back(2);
        temp1/=2;
    }
    for(int i=3;i*i<=temp1;i+=2){
        while(temp1%i == 0){
            temp1/=i;
            factors.push_back(i);
        }
    }
    if(temp1>2){
        factors.push_back(temp1);
        temp1 = 1;
    }
    if(factors.size()<k){
        return false;
    }
    return true;
}
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin>>test;
    while(test--){
        int x,k;
        cin>>x>>k;
        cout<<solve(x,k)<<endl;
    }
    return 0;
}
