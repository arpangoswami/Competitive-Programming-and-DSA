#include<bits/stdc++.h>
using namespace std;
bool check(const vector<int> &solution){
    for(int i=0;i<solution.size();i++){
        if(solution[i] == 0){
            return true;
        }
    }
    return false;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> input;
        map<int,int> books;
        vector<int> solution(n,0);
        for(int i=1;i<=n;i++){
            int temp;
            cin>>temp;
            input.push_back(temp);
            books[temp] = i;
        }
        int i=1;
        while(check(solution)){
            int j = i;
            if(solution[i]!=0){
                i++;
                continue;
            }

        }
    }
}
