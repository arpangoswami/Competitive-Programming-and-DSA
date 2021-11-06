#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
Node* buildTree(){
    int d;
    cin>>d;
    if(d == -1){
        return nullptr;
    }
    Node* root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void printPreorder(Node *root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}
void inorder(Node* root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root == nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(int argc,char const* argv[]){
    Node *root = buildTree();
    printPreorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}