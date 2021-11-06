#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> arr[n];
        vector<bool> visited(n);
        vector<bool> princess(n);
        for(int i=0;i<n;i++){
            visited[i] = false;
            princess[i] = false;
            int siz;
            cin>>siz;
            for(int j=0;j<siz;j++){
                int temp;
                cin>>temp;
                arr[i].push_back(temp);
            }
        }
        int marriages = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<arr[i].size();j++){
                if(visited[arr[i][j]-1] == false){
                    marriages++;
                    visited[arr[i][j]-1] = true;
                    princess[i] = true;
                    break;
                }
            }
        }
        if(marriages == n){
            cout<<"OPTIMAL"<<endl;
        }
        else{
            cout<<"IMPROVE"<<endl;
            int idx1 = -1;
            int idx2 = -1;
            for(int i=0;i<n;i++){
                if(princess[i] == false){
                    idx1 = i+1;
                    break;
                }
            }
            for(int i=0;i<n;i++){
                if(visited[i] == false){
                    idx2 = i+1;
                    break;
                }
            }
            cout<<idx1<<" "<<idx2<<endl;
        }
    }
}
