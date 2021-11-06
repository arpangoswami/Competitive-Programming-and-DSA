#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
void preOrder(Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
Node *treeBuilder(int in[],int post[],int iIn,int jIn,int &toPick){
    if(iIn>jIn){
        return nullptr;
    }
    int val = post[toPick--];
    int idx = -1;
    Node *root = new Node(val);
    for(int i=iIn;i<=jIn;i++){
        if(in[i] == val){
            idx = i;
            break;
        }
    }
    root->right = treeBuilder(in,post,idx+1,jIn,toPick);
    root->left = treeBuilder(in,post,iIn,idx-1,toPick);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    int toPick = n-1;
    Node *root = treeBuilder(in,post,0,n-1,toPick);
    return root;
}
