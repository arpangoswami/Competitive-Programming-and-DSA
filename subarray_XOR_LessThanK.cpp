#include<bits/stdc++.h>
using namespace std;
class trieNode{
public:
    trieNode *left;
    trieNode *right;
    int cnt;
    trieNode(){
        cnt = 0;
        left = nullptr;
        right = nullptr;
    }
};
void addNumber(int num,trieNode *head){
    trieNode *curr = head;
    for(int i=31;i>=0;i--){
        int bit = (num>>i)&1;
        if(bit == 0){
            if(curr->left == nullptr){
                trieNode *n = new trieNode();
                n->cnt = 1;
                curr->left = n;
            }
            else{
                (curr->left->cnt)++;
            }
            curr = curr->left;
        }
        else{
            if(curr->right == nullptr){
                trieNode *n = new trieNode();
                n->cnt = 1;
                curr->right = n;
            }
            else{
                (curr->right->cnt)++;
            }
            curr = curr->right;
        }
    }
}
long long query(int n,int k,trieNode *head){
    trieNode *curr = head;
    long val = 0;
    if(head == nullptr) return 0;
    for(int i=31;i>=0;i--){
        int b1 = (n>>i) & 1;
        int b2 = (k>>i) & 1;
        if(b2 == 1){
            if(b1 == 1){
                if(curr->right){
                    val+=(long long)(curr->right->cnt);
                }
                curr = curr->left;
            }
            else if(b1 == 0){
                if(curr->left){
                    val+=(long long)(curr->left->cnt);
                }
                curr = curr->right;
            }
        }
        else{
            if(b1 == 1){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        if(curr == nullptr){
            break;
        }
    }
    return val;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        trieNode *head = new trieNode();
        int accumulatedXOR = 0;
        long long ans = 0;
        addNumber(accumulatedXOR,head);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            accumulatedXOR^=arr[i];
            ans+=query(accumulatedXOR,k,head);
            addNumber(accumulatedXOR,head);
        }
        cout<<ans<<endl;
    }
}
