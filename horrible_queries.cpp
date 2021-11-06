#include <iostream>
typedef long long ll;
using namespace std;
void update(ll *tree,ll *lazy,int low,int high,int startR,int endR,int i,ll value){
    if(low>high){
        return;
    }
    if(lazy[i]!=0){
        tree[i]+= (high - low + 1) * lazy[i];
        if(low!=high){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i] = 0;
    }
    if(low>endR || high<startR){
        return;
    } 
    if(startR<=low && endR>=high){
        tree[i]+=(high - low + 1)*value;
        if(low!=high){
            lazy[2*i+1]+=value;
            lazy[2*i+2]+=value;
        }
        return;
    }
    int mid = low + (high - low)/2;
    update(tree,lazy,low,mid,startR,endR,2*i+1,value);
    update(tree,lazy,mid+1,high,startR,endR,2*i+2,value);
    tree[i] = tree[2*i+1] + tree[2*i+2];
}
ll query(ll *tree,ll *lazy,int low,int high,int startR,int endR,int i){
    if(low>high){
        return 0;
    }
    if(lazy[i]!=0){
        tree[i]+=(high - low + 1)*lazy[i];
        if(low!=high){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i] = 0;
    }
    if(low>endR || high<startR){
        return 0;
    }
    if(low>=startR && high<=endR){
        return tree[i];
    }
    int mid = low+(high-low)/2;
    ll a1 = query(tree,lazy,low,mid,startR,endR,2*i+1);
    ll a2 = query(tree,lazy,mid+1,high,startR,endR,2*i+2);
    return a1+a2;
}
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test;
    cin>>test;
    while(test--){
        int n,q;
        cin>>n>>q;
        ll *tree = new ll[4*n]();
        ll *lazyTree = new ll[4*n]();
        while(q--){
            int qtype;
            cin>>qtype;
            if(qtype == 0){
                int left,right;
                ll value;
                cin>>left>>right>>value;
                update(tree,lazyTree,0,n-1,left-1,right-1,0,value);
            }
            else{
                int left,right;
                cin>>left>>right;
                cout<<query(tree,lazyTree,0,n-1,left-1,right-1,0)<<endl;
            }
        }
        delete []tree;
        delete []lazyTree;
    }
    return 0;
}