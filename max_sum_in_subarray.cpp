#include<bits/stdc++.h>
using namespace std;
struct node{
    int total_sum;
    int max_sum;
    int prefix_sum;
    int suffix_sum;
};
void buildTree(int *arr,node *tree,int start,int finish,int treeNode){
    if(start==finish){
        tree[treeNode].total_sum=arr[start];
        tree[treeNode].max_sum=arr[start];
        tree[treeNode].prefix_sum=arr[start];
        tree[treeNode].suffix_sum=arr[start];
        return;
    }
    int mid=(start+finish)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,finish,2*treeNode+1);
    node left=tree[2*treeNode];
    node right=tree[2*treeNode+1];
    tree[treeNode].total_sum=(left.total_sum+right.total_sum);
    tree[treeNode].prefix_sum=max(left.prefix_sum,(left.total_sum+right.prefix_sum));
    tree[treeNode].suffix_sum=max(right.suffix_sum,(right.total_sum+left.suffix_sum));
    tree[treeNode].max_sum=max(left.max_sum,max(right.max_sum,max((left.total_sum+right.prefix_sum),max((right.total_sum+left.suffix_sum),(left.suffix_sum+right.prefix_sum)))
    return;
}
node query(node *tree,int start,int finish,int treeNode,int left,int right){
    if(start>right || finish<left){
            node a;
            a.total_sum=0;
            a.secondmax=INT_MIN;
            return a;
    }
    else if(start>=left && finish<=right){
        return tree[treeNode];
    }
    int mid=(start+finish)/2;
    node ans1=query(tree,start,mid,2*treeNode,left,right);
    node ans2=query(tree,mid+1,finish,2*treeNode+1,left,right);
    node temp;
    tree[treeNode].total_sum=(left.total_sum+right.total_sum);
    tree[treeNode].prefix_sum=max(left.prefix_sum,(left.total_sum+right.prefix_sum));
    tree[treeNode].suffix_sum=max(right.suffix_sum,(right.total_sum+left.suffix_sum));
    tree[treeNode].max_sum=max(left.max_sum,max(right.max_sum,max((left.total_sum+right.prefix_sum),max((right.total_sum+left.suffix_sum),(left.suffix_sum+right.prefix_sum)))
    return temp;
}
void updateTree(int *arr,node *tree,int start,int finish,int treeNode,int index,int value){
    if(start==finish){
        arr[index]=value;
        tree[treeNode].total_sum=value;
        tree[treeNode].max_sum=value;
        return;
    }
    int mid=(start+finish)/2;
    if(index>mid){
        updateTree(arr,tree,mid+1,finish,2*treeNode+1,index,value);
    }
    else{
        updateTree(arr,tree,start,mid,2*treeNode,index,value);
    }
    tree[treeNode].maximum=max(tree[2*treeNode].maximum,tree[2*treeNode+1].maximum);
    tree[treeNode].secondmax=min(max((tree[2*treeNode].secondmax),(tree[2*treeNode+1].maximum)),max((tree[2*treeNode].maximum),(tree[2*treeNode+1].secondmax)));
    return;
}
int main(void){
    int n,q;
    cin>>n;
    int *arr=new int[n];
    node *tree=new node[3*n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>q;
    buildTree(arr,tree,0,n-1,1);
    while(q--){
        char c;
        int a,b;
        cin>>c>>a>>b;
        if(c=='Q'){
            node m=query(tree,0,n-1,1,a-1,b-1);
            int sum=(m.maximum+m.secondmax);
            cout<<sum<<endl;
        }
        else if(c=='U'){
            updateTree(arr,tree,0,n-1,1,a-1,b);
        }
    }
    delete []arr;
    delete []tree;
}
