#include<bits/stdc++.h>
using namespace std;
int linearSearch(int *arr,int n,int toSearch){
    for(int i=0;i<n;i++){
        if(arr[i] == toSearch){
            return i;
        }
    }
    return -1;
}
void checkOutOfOrder(int candidate,int **arr,int rows,int cols,vector<int> &indegree0,vector<vector<int> >&representative){
    bool flag;
    for(int j=0;j<representative.size();j++){
        flag = true;
        for(int i=0;i<rows;i++){
            int idx1 = linearSearch(arr[i],cols,candidate);
            int idx2 = linearSearch(arr[i],cols,representative[j].back());
            if(idx1<idx2){
                flag = false;
                break;
            }
        }
        if(flag){
            representative[j].push_back(candidate);
            break;
        }
    }
    if(!flag){
        vector<int> temp;
        temp.push_back(candidate);
        indegree0.push_back(candidate);
        representative.push_back(temp);
    }
}
int main(){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        int **arr = new int *[k];
        for(int i=0;i<k;i++){
            arr[i] = new int[n];
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        vector<int> indegree0;
        vector<vector<int> >representative;
        int *toMatch = new int[n];
        for(int k=0;k<n;k++){
            toMatch[k] = arr[0][k];
        }
        indegree0.push_back(toMatch[0]);
        vector<int> temp;
        temp.push_back(toMatch[0]);
        representative.push_back(temp);
        for(int i=1;i<n;i++){
            checkOutOfOrder(toMatch[i],arr,k,n,indegree0,representative);
        }
        int *graph = new int[n]();
        cout<<indegree0.size()<<endl;
        for(int i=0;i<representative.size();i++){
            for(int j=0;j<representative[i].size();j++){
                cout<<representative[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<representative.size();i++){
            for(int j = 0;j<(representative[i].size()-1);j++){
                graph[representative[i][j] - 1] = representative[i][j+1];
            }
            graph[representative[i].back()-1] = 0;
        }
        for(int i=0;i<n;i++){
            cout<<graph[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<k;i++){
            delete []arr[i];
        }
        delete []arr;
        delete []graph;
        delete []toMatch;
    }
    return 0;
}
