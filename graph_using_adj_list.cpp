#include<iostream>
#include<vector>
using namespace std;
class Graph{
private:
    int vertices;
    vector<int> *adj_list;
public:
    Graph(int v):vertices(v){
        adj_list = new vector<int>[v];
    }
    ~Graph(){
        delete []adj_list;
    }
    void add_edge(int v1,int v2,bool bidir = true){
        if(bidir){
            adj_list[v1].push_back(v2);
            adj_list[v2].push_back(v1);
        }
        else{
            adj_list[v1].push_back(v2);
        }
    }
    void print_adj_list(){
        for(int i=0;i<vertices;i++){
            cout<<i<<"->";
            for(int j=0;j<adj_list[i].size();j++){
                cout<<adj_list[i][j]<<", ";
            }
            cout<<endl;
        }
    }
};
int main(void){
    Graph g(5);
    g.add_edge(0,1);
    g.add_edge(0,4);
    g.add_edge(3,4);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(1,4);
    g.add_edge(1,3);
    g.print_adj_list();
}
