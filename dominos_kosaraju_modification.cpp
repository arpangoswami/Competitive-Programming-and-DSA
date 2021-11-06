#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> *edges,int sv,stack<int> &st,bool *visited1){
    visited1[sv] = true;
    for(int x = 0;x<edges[sv].size();x++){
        int neighbour = edges[sv][x];
        if(!visited1[neighbour]){
            dfs(edges,neighbour,st,visited1);
        }
    }
    st.push(sv);
}
void dfs2(vector<int> *edges,int sv,bool *visited2){
    visited2[sv] = true;
    for(int x = 0;x<edges[sv].size();x++){
        int neighbour = edges[sv][x];
        if(!visited2[neighbour]){
            dfs2(edges,neighbour,visited2);
        }
    }
}
int getSCC(vector<int> *edges,int n,bool *visited1,bool *visited2){
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!visited1[i]){
            dfs(edges,i,st,visited1);
        }
    }
    int output = 0;
    while(!st.empty()){
        int element = st.top();
        st.pop();
        if(!visited2[element]){
            dfs2(edges,element,visited2);
            output++;
        }
    }
    return output;
}
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        vector<int> *edges = new vector<int> [n];
        bool *visited1 = new bool[n]();
        bool *visited2 = new bool[n]();
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            edges[u-1].push_back(v-1);
        }
        int output = getSCC(edges,n,visited1,visited2);
        cout<<output<<endl;
        delete []edges;
        delete []visited1;
        delete []visited2;
	}
    return 0;
}
