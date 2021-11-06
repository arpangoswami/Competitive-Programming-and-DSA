#include<iostream>
#include<queue>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	node(int d){
		data = d;
		left = nullptr;
		right = nullptr;
	}
};
node* buildTree(int *arr,int low,int high){
	if(low > high){
		return nullptr;
	}
	int mid = low + (high - low)/2;
	node *root = new node(arr[mid]);
	root->left = buildTree(arr,low,mid-1);
	root->right = buildTree(arr,mid+1,high);
	return root;
}
void printPreorder(node *root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}
void levelOrder(node* root){
	if(!root){
		return;
	}
	queue <node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
	}
}
void printKthLevel(){
    
}
int main() {
	int test;
	cin>>test;
	while(test--){
		int n;
        cin>>n;
		int *arr = new int[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		int low = 0,high = n-1;
		node *root = buildTree(arr,low,high);
		//levelOrder(root);
        printPreorder(root);
		cout<<endl;
		delete []arr;
	}
	return 0;
}