#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<bool> visited(n-1,false);
        vector<int> input;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            input.push_back(temp);
        }
        int pos;
        for(int i=0;i<n;i++){
            if(input[i] == 1){
                pos = i;
                break;
            }
        }
        for(int i=0;i<pos;i++){
            visited[i] = true;
        }
        int temp = input[pos];
        for(int i=pos;i>0;i--){
            input[i] = input[i-1];
        }
        input[0] = temp;
        int j=2,index = pos;
        while(j<n && index<n-1){
            for(int l=0;l<n;l++){
                if(input[l] == j){
                    pos = l;
                    break;
                }
            }
            if(visited[pos-1] || input[pos-1]<input[pos]){
                j++;
                continue;
            }
            else{
                int m = pos-1;
                while(visited[m] == false && input[m]>j){
                    visited[m] = true;
                    m--;
                }
                for(int k=pos;k>m;k--){
                    input[k] = input[k-1];
                }
                input[m+1] = j;
                index = pos;
                j++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<input[i]<<" ";
        }
        cout<<endl;

    }
}
