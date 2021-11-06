#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<char,char> parent;
unordered_map<char,int> rankHeight;
char findParent(char x){
    if(x == parent[x]){
        return x;
    }
    char par = findParent(parent[x]);
    parent[x] = par;
    return par;
}
void unionByRank(char x,char y){
    char x_rep = findParent(x),y_rep= findParent(y);
    if(x_rep == y_rep) return;
    else if(rankHeight[x_rep]>rankHeight[y_rep]){
        parent[y_rep] = x_rep;
    }
    else if(rankHeight[y_rep]>rankHeight[x_rep]){
        parent[x_rep] = y_rep;
    }
    else{
        parent[y_rep] = x_rep;
        rankHeight[x_rep]++;
    }
}
char findMinimal(char c){
    char x_rep = findParent(c);
    for(int i=0;i<26;i++){
        if(findParent((char)(97+i)) == x_rep){
            return (char)(97+i);
        }
    }
    return 'z';
}
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string A,B,C;
    cin>>A>>B>>C;
    for(int i=0;i<26;i++){
        parent[(char)(97+i)] = (char)(97+i);
        rankHeight[(char)(97+i)] = 1;
    }
    for(int i=0;i<A.size();i++){
        unionByRank(A[i],B[i]);
    }
    for(int i=0;i<C.size();i++){
        char c = findMinimal(C[i]);
        C[i] = c;
    }
    cout<<C<<endl;
    return 0;
}
