#include<bits/stdc++.h>
using namespace std;
class trieNode{
public:
    trieNode *left;
    trieNode *right;
};
void insertNode(int n,trieNode *head){
    trieNode *curr=head;
    for(int i=31;i>=0;i--){
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
int findMaxXORPair(trieNode *head,int arr[],int n){
    int max_xor=INT_MIN;
    for(int i=0;i<n;i++){
        trieNode *curr=head;
        int value=arr[i];
        int curr_xor=0;
        for(int j=31;j>=0;j--){
            int b=(value>>j)&1;
            if(b==0){
                if(curr->right){
                    curr_xor+=pow(2,j);
                    curr=curr->right;
                }
                else{
                    curr=curr->left;
                }
            }else{
                if(curr->left){
                    curr_xor+=pow(2,j);
                    curr=curr->left;
                    }else{
                        curr=curr->right;
                    }
                }

            }
            cout<<curr_xor<<endl;
            if(curr_xor>max_xor){
                max_xor=curr_xor;
            }
        }
    return max_xor;
}
int main(void){
    int arr[4]={1,2,3,4};
    trieNode *head=new trieNode();
    for(int i=0;i<4;i++)
        insertNode(arr[i],head);
    cout<<"Max_xor= "<<findMaxXORPair(head,arr,4)<<endl;
}
