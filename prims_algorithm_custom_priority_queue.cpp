#include <bits/stdc++.h>
using namespace std;
//implementation of minHeap
unordered_map<int,int> mp;
void upHeapify(vector<pair<int,int> > &heap ,int idx){
    if(idx == 0){
        return;
    }
    int parentIdx = (idx-1)/2;
    if(heap[idx].second<heap[parentIdx].second){
        swap(heap[idx],heap[parentIdx]);
        mp[idx] = parentIdx;
        mp[parentIdx] = idx;
        upHeapify(heap,parentIdx);
    }
}
void downHeapify(vector<pair<int,int> > &heap,int idx){
    int lchild = 2*idx + 1;
    int rchild = 2*idx + 2;
    if(lchild>=heap.size() && rchild>=heap.size()){
        return;
    }
    int smallestIdx = idx;
    if(lchild<heap.size() && heap[lchild].second<heap[smallestIdx].second){
        smallestIdx = lchild;
    }
    if(rchild<heap.size() && heap[rchild].second<heap[smallestIdx].second){
        smallestIdx = rchild;
    }
    if(smallestIdx!=idx){
        swap(heap[smallestIdx],heap[idx]);
        mp[smallestIdx] = idx;
        mp[idx] = smallestIdx;
        downHeapify(heap,smallestIdx);
    }
}
void deletePeak(vector<pair<int,int> > &heap){
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    downHeapify(heap,0);
}
void buildHeap(vector<pair<int,int> > &heap){
    for(int i=0;i<heap.size();i++){
        upHeapify(heap,i);
    }
}
void buildHeapOptimized(vector<pair<int,int> > &heap){
    for(int i=(heap.size()-1);i>=0;i--){
        downHeapify(heap,i);
    }
}
void decreaseKey(vector<pair<int,int> > &heap,int i,int x){
    heap[i].second = x;
    upHeapify(heap,i);
}
void prims(vector<pair<int,int> > *adj_list,int n){
    vector<bool> visited(n,false);
    vector<int> parent(n,-1);
    vector<pair<int,int> > weight(n);
    for(int i=0;i<n;i++){
        weight[i].first = i;
        weight[i].second = INT_MAX;
        mp[i] = i;
    }
    weight[0].second = 0;
    buildHeapOptimized(weight);
    cout<<"yoo"<<endl;
    for(int i=0;i<n;i++){
        cout<<weight[i].first<<" "<<weight[i].second<<endl;
    }
    cout<<"yoo"<<endl;
    for(int i=0;i<(n-1);i++){
        int minVertex = weight[0].first;
        deletePeak(weight);
        cout<<"happy"<<endl;
        for(int i=0;i<weight.size();i++){
            cout<<weight[i].first<<" "<<weight[i].second<<endl;
        }
        cout<<"happy"<<endl;
        for(int j=0;j<adj_list[minVertex].size();j++){
            int v = adj_list[minVertex][j].first;
            int wt = adj_list[minVertex][j].second;
            int key = mp[v];
            if(visited[v] == false && weight[key].second>wt){
                decreaseKey(weight,key,wt);
                key = mp[v];
                parent[v] = minVertex;
                cout<<"sad"<<endl;
                for(int i=0;i<weight.size();i++){
                    cout<<weight[i].first<<" "<<weight[i].second<<endl;
                }
                cout<<"sad"<<endl;
            }
        }
    }
    for(int i=1;i<n;i++){
        if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<" "<<weight[mp[i]].second<<endl;
        }
        else{
            cout<<i<<" "<<parent[i]<<" "<<weight[mp[i]].second<<endl;
        }
    }
}
int main(int argc,char const* argv[]){
    int n,e;
    cin>>n>>e;
    vector<pair<int,int> > *adj_list = new vector<pair<int,int> > [n];
    for(int i=0;i<e;i++){
        int src,dest,weight;
        cin>>src>>dest>>weight;
        adj_list[src].push_back(make_pair(dest,weight));
        adj_list[dest].push_back(make_pair(src,weight));
    }
    prims(adj_list,n);
    delete []adj_list;
    return 0;
}
