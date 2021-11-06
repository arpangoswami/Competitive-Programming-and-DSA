#include<bits/stdc++.h>
using namespace std;
int fin(int x,int parent[]){
    if(x==parent[x]){
        return x;
    }
    parent[x] = fin(parent[x],parent);
    return parent[x];
}
void unio(int x,int y,int parent[],int rank1[]){
    int x_ref = fin(x,parent);
    int y_ref = fin(y,parent);
    if(x_ref==y_ref) return;
    if(rank1[x_ref]<rank1[y_ref]){
        parent[x_ref] = y_ref;
    }
    else if(rank1[x_ref]>rank1[y_ref]){
        parent[y_ref] = x_ref;
    }
    else{
        parent[x_ref] = y_ref;
        rank1[y_ref]++;
    }
}
int main(void){
    int n,queries;
    cin>>n>>queries;
    int parent[n+1],rank1[n+1]={0};
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    while(queries--){
        int type,v1,v2;
        cin>>type>>v1>>v2;
        if(type==1){
            unio(v1,v2,parent,rank1);
        }
        else{
            int v1_ref = fin(v1,parent),v2_ref = fin(v2,parent);
            if(v1_ref==v2_ref){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
}
