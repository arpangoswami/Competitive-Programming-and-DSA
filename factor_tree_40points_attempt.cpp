#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
const long long mod = 1000000007;
using namespace std;
class Graph{
public:
    long long vertices;
    vector<long long> *adj_list;
    unordered_map<long long,long long> **mp;
    long long *weight;
    Graph(long long v){
        vertices = v;
        adj_list = new vector<long long> [v+1]();
        weight = new long long [v+1]();
        mp = new unordered_map<long long,long long> *[v+1];
        for(int i=0;i<=v;i++){
            mp[i] = new unordered_map<long long,long long> [v+1]();
        }
    }
    ~Graph(){
        delete []weight;
        delete []adj_list;
        for(long long i=0;i<=vertices;++i){
            delete []mp[i];
        }
        delete []mp;
    }
    void addEdge(long long u,long long v){
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    unordered_map<long long,long long> factors(long long n){
        unordered_map<long long,long long>res;
        while(n%2 == 0){
            res[2]++;
            n/=2;
        }
        for(long long i=3;(i*i)<=n;i+=2){
            while(n%i == 0){
                res[i]++;
                n/=i;
            }
        }
        if(n>2){
            res[n]++;
        }
        return res;
    }
    unordered_map<long long,long long> primeFactorsMultiply(unordered_map<long long,long long> mp1,unordered_map<long long,long long> mp2){
        unordered_map<long long,long long> res;
        for(auto it = mp1.begin();it!=mp1.end();++it){
            if(mp2.count(it->first)){
                res[it->first] = mp1[it->first] + mp2[it->first];
            }
            else{
                res[it->first] = mp1[it->first];
            }
        }
        for(auto it = mp2.begin();it!=mp2.end();++it){
            if(mp1.count(it->first) == 0){
                res[it->first] = mp2[it->first];
            }
        }
        return res;
    }
    void BFS(long long vertex){
        bool *visited = new bool[vertices+1]();
        visited[vertex] = true;
        queue<long long>q;
        mp[vertex][vertex] = factors(weight[vertex]);
        q.push(vertex);
        while(!q.empty()){
            long long x = q.front();
            q.pop();
            for(int i=0;i<adj_list[x].size();i++){
                long long neighbour = adj_list[x][i];
                if(visited[neighbour] == false){
                    q.push(neighbour);
                    visited[neighbour] = true;
                    mp[vertex][neighbour] = primeFactorsMultiply(mp[vertex][x],factors(weight[neighbour]));
                }
            }
        }
        delete []visited;
    }
};
long long countFactors(unordered_map<long long,long long> mp){
    long long ans = 1;
    for(auto it = mp.begin();it!=mp.end();++it){
        ans = (ans%mod * (it->second+1)%mod)%mod;
    }
    return ans%mod;
}
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
        for(long long i=1;i<=(n-1);++i){
            long long u,v;
            cin>>u>>v;
            g.addEdge(u,v);
        }
        for(long long i=1;i<=n;++i){
            cin>>g.weight[i];
        }
        for(long long i=1;i<=n;i++){
            g.BFS(i);
        }
        int queries;
        cin>>queries;
        while(queries--){
            long long x,y;
            cin>>x>>y;
            long long ans = countFactors(g.mp[x][y]);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
