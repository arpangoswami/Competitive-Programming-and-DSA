#include<bits/stdc++.h>
using namespace std;
class trieNode{
public:
    int value;
    trieNode *left;
    trieNode *right;
    trieNode(){
        value = 0;
        left = NULL;
        right = NULL;
    }
};
void insertData(int n,trieNode *head){
    trieNode *curr = head;
    for(int i=31;i>=0;i--){
        int bit = (n>>i)&1;
        if(bit == 0){
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
int findMinimumXorPairValueTillNow(int n,trieNode *head){
    trieNode *curr = head;
    int curr_xor = 0;
    for(int i=31;i>=0;i--){
        int bit = (n>>i)&1;
        if(bit == 0){
            if(curr->left){
                curr = curr->left;
            }
            else{
                curr_xor+=(1<<i);
                curr = curr->right;
            }
        }
        else{
            if(curr->right){
                curr = curr->right;
            }
            else{
                curr_xor+=(1<<i);
                curr = curr->left;
            }
        }
    }
    return curr_xor;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int *arr = new int [n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        trieNode *head = new trieNode();
        insertData(arr[0],head);
        int minXor = INT_MAX;
        for(int i=1;i<n;i++){
            int currentMinXor = findMinimumXorPairValueTillNow(arr[i],head);
            minXor = min(minXor,currentMinXor);
            insertData(arr[i],head);
        }
        cout<<minXor<<endl;
        delete []arr;
        delete head;
    }
}
