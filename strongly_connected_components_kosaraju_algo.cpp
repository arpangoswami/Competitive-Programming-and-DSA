#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> *edges,int sv,stack<int> &st,unordered_set<int> &visited){
    visited.insert(sv);
    for(int x = 0;x<edges[sv].size();x++){
        int neighbour = edges[sv][x];
        if(visited.count(neighbour) == 0){
            dfs(edges,neighbour,st,visited);
        }
    }
    st.push(sv);
}
void dfs2(vector<int> *edgesT,int sv,unordered_set<int> &visited,unordered_set<int> *component){
    component->insert(sv);
    visited.insert(sv);
    for(int x = 0;x<edgesT[sv].size();x++){
        int neighbour = edgesT[sv][x];
        if(visited.count(neighbour) == 0){
            dfs2(edgesT,neighbour,visited,component);
        }
    }
}
unordered_set<unordered_set<int>* >* getSCC(vector<int> *edges,vector<int> *edgesT,int n){
    unordered_set<int> visited;
    stack<int> st;
    for(int i=0;i<n;i++){
        if(visited.count(i) == 0){
            dfs(edges,i,st,visited);
        }
    }
    unordered_set<unordered_set<int>* >* output = new unordered_set<unordered_set<int>* >();
    visited.clear();
    while(!st.empty()){
        int element = st.top();
        st.pop();
        if(visited.count(element) == 0){
            unordered_set<int>* component = new unordered_set<int>();
            dfs2(edgesT,element,visited,component);
            output->insert(component);
        }
    }
    return output;
}
int main(int argc,char const* argv[]){
    int n;
    cin>>n;
    vector<int> *edges = new vector<int> [n];
    vector<int> *edgesT = new vector<int> [n];
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u-1].push_back(v-1);
        edgesT[v-1].push_back(u-1);
    }
    unordered_set<unordered_set<int>* >* output = getSCC(edges,edgesT,n);
    for(auto x = output->begin();x!=output->end();x++){
        unordered_set<int>*s = *x;
        for(auto y = s->begin();y!=s->end();y++){
            cout<<(*y)+1<<" ";
        }
        cout<<endl;
    }
    delete []edges;
    delete []edgesT;
    return 0;
}
/*10
12
1 2
2 3
3 9
9 1
3 4
4 5
5 6
6 4
7 6
7 8
8 7
8 10*/
