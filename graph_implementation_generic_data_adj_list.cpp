#include<iostream>
#include<vector>
#include<map>
using namespace std;
template<class T>
class Graph{
private:
    map<T,vector<T> >adj_list;
public:
    void add_edge(T u,T v,bool bidir = true){
        adj_list[u].push_back(v);
        if(bidir)
            adj_list[v].push_back(u);
    }
    void print(){
        for(auto x:adj_list){
            cout<<x.first<<"->";
            for(T i:x.second){
                cout<<i<<",";
            }
            cout<<endl;
        }
    }
};
int main(void){
    Graph <string> g;
    g.add_edge("Putin","Trump",false);
    g.add_edge("Putin","Modi",false);
    g.add_edge("Putin","Pope",false);
    g.add_edge("Modi","Trump");
    g.add_edge("Modi","Yogi");
    g.add_edge("Yogi","Prabhu",false);
    g.add_edge("Prabhu","Modi",false);
    g.print();
}
