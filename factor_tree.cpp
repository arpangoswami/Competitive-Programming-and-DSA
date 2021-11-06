#include <iostream>
#include <vector>
#include <unordered_map>
const long long mod = 1000000007;
using namespace std;
class Graph{
    long long vertices;
    vector<long long> *adjacency_list;
public:
    long long *weight;
    Graph(long long v){
        vertices = v;
        weight = new long long [v+1]();
        adjacency_list = new vector<long long> [v+1];
    }
    ~Graph(){
        delete []weight;
        delete []adjacency_list;
    }
    void addEdge(long long u,long long v){
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }
    unordered_map<long long,long long> factors(long long n){
        unordered_map<long long,long long>mp;
        while(n%2 == 0){
            mp[2]++;
            n/=2;
        }
        for(long long i=3;(i*i)<=n;i+=2){
            while(n%i == 0){
                mp[i]++;
                n/=i;
            }
        }
        if(n>2){
            mp[n]++;
        }
        return mp;
    }
    unordered_map<long long,long long> productOfNodes(vector<long long> st){
        unordered_map<long long,long long>res;
        for(int i=0;i<st.size();i++){
            unordered_map<long long,long long> temp = factors(weight[st[i]]);
            for(auto it=temp.begin();it!=temp.end();++it){
                if(res.count(it->first)){
                    res[it->first] = res[it->first]+temp[it->first];
                }
                else{
                    res[it->first] = temp[it->first];
                }
            }
        }
        return res;
    }
    bool DFS(int x,int y,vector<bool> &visited,vector<long long>&st){
        st.push_back(x);
        if(x == y){
            return true;
        }
        visited[x] = true;
        for(int j=0;j<adjacency_list[x].size();j++){
            if(visited[adjacency_list[x][j]] == false){
                if(DFS(adjacency_list[x][j],y,visited,st)){
                    return true;
                }
            }
        }
        st.pop_back();
        visited[x] = false;
        return false;
    }
    void DFSCall(int start,int finish,vector<long long>&st){
        vector<bool> visited(vertices+1,false);
        DFS(start,finish,visited,st);
    }
};
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test;
    cin>>test;
    while(test--){
        long long n;
        cin>>n;
        Graph g(n);
        for(long long i=1;i<=(n-1);i++){
            long long u,v;
            cin>>u>>v;
            g.addEdge(u,v);
        }
        for(long long i=1;i<=n;i++){
            cin>>g.weight[i];
        }
        long long queries;
        cin>>queries;
        while(queries--){
            long long x,y;
            cin>>x>>y;
            if(x!=y){
                vector<long long>st;
                g.DFSCall(x,y,st);
                long long ans = 1;
                unordered_map<long long,long long> mp = g.productOfNodes(st);
                for(auto it = mp.begin();it!=mp.end();++it){
                    ans = (ans%mod * (it->second+1)%mod)%mod;
                }
                cout<<ans%mod<<endl;
            }
            else{
                unordered_map<long long,long long> mp= g.factors(g.weight[x]);
                long long ans = 1;
                for(auto it = mp.begin();it!=mp.end();++it){
                    ans = (ans%mod * (it->second+1)%mod)%mod;
                }
                cout<<ans%mod<<endl;
            }
        }
    }
    return 0;
}
