#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct treeNode{
    ll sum_of_squares;
    ll sum_of_interval;
    treeNode(){
        sum_of_interval = 0;
        sum_of_squares = 0;
    }
};
struct lazyNode{
    ll set_range;
    ll update_range;
    lazyNode(){
        set_range = 0;
        update_range = 0;
    }
};
void buildTree(ll *arr,treeNode *tree,int start,int end,int pos){
    if(start == end){
        tree[pos].sum_of_squares = arr[start]*arr[start];
        tree[pos].sum_of_interval = arr[start];
        return;
    }
    int mid = start + (end-start)/2;
    buildTree(arr,tree,start,mid,2*pos+1);
    buildTree(arr,tree,mid+1,end,2*pos+2);
    tree[pos].sum_of_squares = tree[2*pos+1].sum_of_squares + tree[2*pos+2].sum_of_squares;
    tree[pos].sum_of_interval = tree[2*pos+1].sum_of_interval + tree[2*pos+2].sum_of_interval;
}
void update(treeNode *tree,lazyNode *lazyTree,int start,int end,int low,int high,int qtype,int pos,ll val){
    if(low > high){
        return;
    }
    if(lazyTree[pos].set_range!=0){
        ll x = lazyTree[pos].set_range;
        tree[pos].sum_of_squares = ((x*x)*(high-low+1));
        tree[pos].sum_of_interval = (x*(high-low+1));
        if(low!=high){
            lazyTree[2*pos+1].set_range = x;
            lazyTree[2*pos+1].update_range = 0;
            lazyTree[2*pos+2].set_range = x;
            lazyTree[2*pos+2].update_range = 0;
        }
        lazyTree[pos].set_range = 0;
    }
    if(lazyTree[pos].update_range!=0){
        ll x = lazyTree[pos].update_range;
        tree[pos].sum_of_squares += ((x*x)*(high - low + 1) + 2*x*(tree[pos].sum_of_interval));
        tree[pos].sum_of_interval += ((x*(high - low + 1)));
        if(low!=high){
            lazyTree[2*pos+1].update_range = x;
            lazyTree[2*pos+2].update_range = x;
        }
        lazyTree[pos].update_range = 0;
    }
    //No overlap
    if(low > end || high<start){
        return;
    }
    //Complete overlap
    if(low>=start && high<=end){
        if(qtype == 0){
            tree[pos].sum_of_squares = (val*val)*(high - low + 1);
            tree[pos].sum_of_interval = (val)*(high - low + 1);
            if(low!=high){
                lazyTree[2*pos+1].update_range = 0;
                lazyTree[2*pos+2].update_range = 0;
                lazyTree[2*pos+1].set_range = val;
                lazyTree[2*pos+2].set_range = val;
            }
        }
        else if(qtype == 1){
            tree[pos].sum_of_squares += (val*val)*(high - low + 1) + 2*val*(tree[pos].sum_of_interval);
            tree[pos].sum_of_interval += (val)*(high - low + 1);
            if(low!=high){
                lazyTree[2*pos+1].update_range += val;
                lazyTree[2*pos+2].update_range += val;
            }
        }
        return;
    }
    int mid = low + (high - low)/2;
    update(tree,lazyTree,start,end,low,mid,qtype,2*pos+1,val);
    update(tree,lazyTree,start,end,mid+1,high,qtype,2*pos+2,val);
    tree[pos].sum_of_squares = tree[2*pos+1].sum_of_squares + tree[2*pos+2].sum_of_squares;
    tree[pos].sum_of_interval = tree[2*pos+1].sum_of_interval + tree[2*pos+2].sum_of_interval;
}
ll query(treeNode *tree,lazyNode *lazyTree,int start,int end,int low,int high,int pos){
    if(low > high){
        return 0;
    }
    if(lazyTree[pos].set_range!=0){
        ll x = lazyTree[pos].set_range;
        tree[pos].sum_of_squares = ((x*x)*(high-low+1));
        tree[pos].sum_of_interval = (x*(high-low+1));
        if(low!=high){
            lazyTree[2*pos+1].set_range = x;
            lazyTree[2*pos+2].set_range = x;
            lazyTree[2*pos+1].update_range = 0;
            lazyTree[2*pos+2].update_range = 0;
        }
        lazyTree[pos].set_range = 0;
    }
    if(lazyTree[pos].update_range!=0){
        ll x = lazyTree[pos].update_range;
        tree[pos].sum_of_squares += ((x*x)*(high - low + 1) + 2*x*(tree[pos].sum_of_interval));
        tree[pos].sum_of_interval += ((x*(high - low + 1)));
        if(low!=high){
            lazyTree[2*pos+1].update_range = x;
            lazyTree[2*pos+2].update_range = x;
        }
        lazyTree[pos].update_range = 0;
    }
    if(low>end || high<start){
        return 0;
    }
    if(low>=start && high<=end){
        return tree[pos].sum_of_squares;
    }
    int mid = low + (high - low)/2;
    ll ans1 = query(tree,lazyTree,start,end,low,mid,2*pos+1);
    ll ans2 = query(tree,lazyTree,start,end,mid+1,high,2*pos+2);
    return ans1+ans2;
}
int main(int argc,char const* argv[]){
    int tests;
    cin>>tests;
    for(int i=1;i<=tests;i++){
        cout<<"Case "<<i<<":"<<endl;
        int n,q;
        cin>>n>>q;
        ll *arr = new ll[n]();
        treeNode *tree = new treeNode[4*n]();
        lazyNode *lazyTree = new lazyNode[4*n]();
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        buildTree(arr,tree,0,n-1,0);
        while(q--){
            int qtype;
            cin>>qtype;
            if(qtype == 2){
                int left,right;
                cin>>left>>right;
                cout<<query(tree,lazyTree,left-1,right-1,0,n-1,0)<<endl;
            }
            else if(qtype == 1){
                int left,right;
                ll value;
                cin>>left>>right>>value;
                update(tree,lazyTree,left-1,right-1,0,n-1,1,0,value);
            }
            else if(qtype == 0){
                int left,right;
                ll value;
                cin>>left>>right>>value;
                update(tree,lazyTree,left-1,right-1,0,n-1,0,0,value);
            }
        }
        delete []arr;
        delete []tree;
        delete []lazyTree;
    }
    return 0;
}