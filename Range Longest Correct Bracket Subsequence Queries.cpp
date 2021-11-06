#include <bits/stdc++.h>
using namespace std;
struct element{
    int maxLength;
    int left;
    int right;
    element(){
        maxLength = left = right = 0;
    }
};
element mergeElement(element e1,element e2){
    element e;
    int minmatch = min(e1.left,e2.right);
    e.maxLength = e1.maxLength+e2.maxLength + minmatch;
    e.left = e1.left+e2.left - minmatch;
    e.right = e1.right+e2.right - minmatch;
    return e;
}
void buildTree(string &s,element *tree,int start,int finish,int treeNode){
    if(start == finish){
        element e;
        if(s[start] == '('){
            e.maxLength = 0;
            e.left = 1;
            e.right = 0;
        }
        else{
            e.maxLength = 0;
            e.left = 0;
            e.right = 1;
        }
        tree[treeNode] = e;
        return;
    }
    int mid = start + (finish-start)/2;
    buildTree(s,tree,start,mid,2*treeNode+1);
    buildTree(s,tree,mid+1,finish,2*treeNode+2);
    element e1 = tree[2*treeNode+1],e2 = tree[2*treeNode+2];
    element e3;
    e3 = mergeElement(e1,e2);
    tree[treeNode] = e3;
}
element query(element *tree,int start,int finish,int treeNode,int left,int right){
    if(start>right || finish<left){
        return element();
    }
    else if(start>=left && finish<=right){
        return tree[treeNode];
    }
    int mid = start + (finish-start)/2;
    element e1 = query(tree,start,mid,2*treeNode+1,left,right);
    element e2 = query(tree,mid+1,finish,2*treeNode+2,left,right);
    element e3 = mergeElement(e1,e2);
    return e3;
}
int main(int argc,char const* argv[]){
    int test;
    cin>>test;
    while(test--){
        string s;
        cin>>s;
        int q;
        cin>>q;
        int n = s.size();
        element *tree = new element[4*n]();
        buildTree(s,tree,0,n-1,0);
        while(q--){
            int left,right;
            cin>>left>>right;
            element e = query(tree,0,n-1,0,left,right);
            cout<<2*e.maxLength<<endl;
        }
        delete []tree;
    }
    return 0;
}
