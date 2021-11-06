/*BOTTOM
Send Feedback
We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Specification
The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.
Output Specification
For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.
Sample Input
3 3
1 3 2 3 3 1
2 1
1 2
0
Sample Output
1 3
2*/
#include <iostream>
#include <unordered_set>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;
void dfs(set<int> *edges,int sv,stack<int> &st,unordered_set<int> &visited){
    visited.insert(sv);
    for(int x : edges[sv]){
        int neighbour = x;
        if(visited.count(neighbour) == 0){
            dfs(edges,neighbour,st,visited);
        }
    }
    st.push(sv);
}
void dfs2(set<int> *edgesT,int sv,unordered_set<int> &visited,unordered_set<int> *component){
    component->insert(sv);
    visited.insert(sv);
    for(int x : edgesT[sv]){
        int neighbour = x;
        if(visited.count(neighbour) == 0){
            dfs2(edgesT,neighbour,visited,component);
        }
    }
}
unordered_set<unordered_set<int>* >* getSCC(set<int> *edges,set<int> *edgesT,int n){
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
bool check(int sv,set<int> *edges,unordered_set<int>* s){
    for(int x:edges[sv]){
        int nb = x;
        if(s->count(nb) == 0){
            return false;
        }
    }
    return true;
}
int main(int argc,char const* argv[]){
        int n,m;
        cin>>n>>m;
        set<int> *edges = new set<int>[n]();
        set<int> *edgesT = new set<int>[n]();
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            edges[u-1].insert(v-1);
            edgesT[v-1].insert(u-1);
        }
        unordered_set<unordered_set<int>* >* output = getSCC(edges,edgesT,n);
        vector<int> v;
        for(auto it = output->begin();it!=output->end();it++){
            bool flag = true;
            unordered_set<int>* s = *it;
            for(auto it2 = s->begin();it2!=s->end();it2++){
                flag = check(*it2,edges,s);
                if(!flag){
                    break;
                }
            }

            if(flag){
                for(auto it2 = s->begin();it2!=s->end();it2++){
                    v.push_back((*it2)+1);
                }
            }
            delete s;
        }
        cout<<v.size()<<endl;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        delete output;
        delete []edges;
        delete []edgesT;
    return 0;
}
