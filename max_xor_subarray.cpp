#include<bits/stdc++.h>
using namespace std;
class trieNode{
public:
    trieNode *left;
    trieNode *right;
};
void insertNode(int n,trieNode *head){
    trieNode *curr=head;
    for(int i=17;i>=0;i--){
        int b=(n>>i)&1;
        if(b==0){
            if(!curr->left)
                curr->left=new trieNode();
            curr=curr->left;
        }
        else{
            if(!curr->right)
                curr->right=new trieNode();
            curr=curr->right;
        }
    }
}
int findMaxXORPair(trieNode *head,int value){
    trieNode *curr=head;
    int curr_xor=0;
    for(int j=17;j>=0;j--){
        int b=(value>>j)&1;
        if(b==0){
            if(curr->right){
                curr_xor+=(1<<j);
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        else{
            if(curr->left){
                curr_xor+=(1<<j);
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
    }
    //cout<<"curr_xor= "<<curr_xor<<endl;
    return curr_xor;
}
int main(void){
    int n;
    cin>>n;
    int ans=0,pre=0;
    int *arr=new int [n];
    trieNode *head=new trieNode();
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        pre=pre^arr[i];
        insertNode(pre,head);
        ans=max(ans,findMaxXORPair(head,pre));
    }
    cout<<ans<<endl;
}
