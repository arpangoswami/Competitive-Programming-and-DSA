#include<bits/stdc++.h>
using namespace std;
class trieNode{
    public:
    trieNode *left;
    trieNode *right;
};
void insertNode(int n,trieNode *head){
    trieNode *curr = head;
    for(int i=31;i>=0;i--){
        int bit = ((n>>i)&1);
        if(bit==0){
            if(curr->left == NULL){
                curr->left = new trieNode();
            }
            curr = curr->left;
        }
        else{
            if(curr->right == NULL){
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
}
int findMaxXorPair(trieNode *head,int arr[],int n){
    int max_xor = INT_MIN;
    for(int i=0;i<n;i++){
        trieNode *curr = head;
        int value = arr[i];
        int curr_xor = 0;
        for(int j=31;j>=0;j--){
            int bit = (value>>j)&1;
            if(bit==0){
                if(curr->right!=NULL){
                    curr_xor+=(1<<j);
                    curr = curr->right;
                }
                else{
                    curr = curr->right;
                }
            }
            else{
                if(curr->left!=NULL){
                    curr_xor+=(1<<j);
                    curr = curr->left;
                }
                else{
                    curr = curr->right;
                }
            }
        }
        max_xor = max(max_xor,curr_xor);
    }
    return max_xor;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int arr[n];
        trieNode *head = new trieNode();
        for(int i=0;i<n;i++){
            cin>>arr[i];
            insertNode(arr[i],head);
        }
        cout<<findMaxXorPair(head,arr,n)<<endl;
        //delete head;
    }
}
