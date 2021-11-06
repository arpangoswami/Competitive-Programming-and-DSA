#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    if(a > b){
        swap(a,b);
    }
    if(a == 0){
        return b;
    }
    return gcd(b%a,a);
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
void buildTree(ll tree[],ll arr [],int node,int start,int finish){
    if(left == right){
        tree[node] = arr[left];
        return;
    }
    int mid = start + (finish - start)/2;
    buildTree(tree,arr,2*node+1,start,mid);
    buildTree(tree,arr,2*node+2,mid+1,finish);
    ll ans1 = tree[2*node+1];
    ll ans2 = tree[2*node+2];
    tree[node] = lcm(ans1,ans2);
}
void update(ll tree[],ll arr[],int node,int start,int finish,int idx,ll val){
    if(start == finish){
        arr[idx] = val;
        tree[node] = val;
        return;
    }
    int mid = start + (finish - start)/2;
    if(idx>mid){
        update(tree,arr,2*node+2,mid+1,finish,idx,val);
    }else{
        update(tree,arr,2*node+1,start,mid,idx,val);
    }
    ll ans1 = tree[2*node+1];
    ll ans2 = tree[2*node+2];
    tree[node] = lcm(ans1,ans2);
}
ll query(ll tree[],int node,int start,int finish,int l,int r){
    if(start>r || finish<l){
        return 1;
    }
    else if(start>=l && finish<=r){
        return tree[node];
    }
    int mid = start + (finish - start)/2;
    ll ans1 = query(tree,2*node+1,start,mid,l,r);
    ll ans2 = query(tree,2*node+2,mid+1,finish,l,r);
    return lcm(ans1,ans2);
}
int main(){
    int test;
    cin>>test;
    while(test--){
        int n,q;
        cin>>n>>q;
        ll arr[n];
        ll tree[4*n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        buildTree(tree,arr,0,0,n-1);
        while(q--){
            char type;
            cin>>type;
            if(type == 'U'){
                int idx;
                ll val;
                cin>>idx>>val;
                update(tree,arr,0,0,n-1,idx,val);
            }else{
                
                int left,right;
                cin>>left>>right;
                cout<<query(tree,0,0,n-1,left,right)<<endl;
            }
        }
    }
    return 0;
}