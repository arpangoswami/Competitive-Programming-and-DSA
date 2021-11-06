#include<bits/stdc++.h>
using namespace std;
struct node{
    int maximum;
    int secondmax;
};
void buildTree(int *arr,node *tree,int start,int finish,int treeNode){
    if(start==finish){
        tree[treeNode].maximum=arr[start];
        tree[treeNode].secondmax=INT_MIN;
        return;
    }
    int mid=(start+finish)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,finish,2*treeNode+1);
    node left=tree[2*treeNode];
    node right=tree[2*treeNode+1];
    tree[treeNode].maximum=max(left.maximum,right.maximum);
    tree[treeNode].secondmax=min(max(left.maximum,right.secondmax),max(left.secondmax,right.maximum));
    return;
}
node query(node *tree,int start,int finish,int treeNode,int left,int right){
    if(start>right || finish<left){
            node a;
            a.maximum=INT_MIN;
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
    temp.maximum=max(ans1.maximum,ans2.maximum);
    temp.secondmax=min(max(ans1.maximum,ans2.secondmax),max(ans1.secondmax,ans2.maximum));
    return temp;
}
void updateTree(int *arr,node *tree,int start,int finish,int treeNode,int index,int value){
    if(start==finish){
        arr[index]=value;
        tree[treeNode].maximum=value;
        tree[treeNode].secondmax=INT_MIN;
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
