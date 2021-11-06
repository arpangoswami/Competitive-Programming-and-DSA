/*You are given an array and Q queries of two types. Type 0: Given a number x , insert the number at the last of the array. Type 1: Given a number X and two integers L, R, Find a number Y in the range L, R to maximize X ^ Y

Input Format
First line of the test case will be the number of queries Q . Then on next Q subsequent lines you will be given a query either of type 0 or type 1. Query of type 0 is of the form : 0 X, where X is the integer to be inserted . Query of type 1 is of the form : 1 L R X

Constraints
0 <= element of array <= 10^9 1 <= N <= 10^5

Output Format
For each query of type 1 output the desired value.

Sample Input
5
0 3
0 5
0 10
0 6
1 1 4 6
Sample Output
10*/
#include<bits/stdc++.h>
using namespace std;
class trieNode{
public:
    trieNode *left;
    trieNode *right;
    int value;
    vector<int> indexes;
    trieNode(){
        left = NULL;
        right = NULL;
        value = 0;
    }
};
void insertNumber(trieNode *root,int n,int idx){
    trieNode *curr = root;
    for(int i=31;i>=0;i--){
        int bit = (n>>i)&1;
        if(bit == 0){
            if(curr->left == NULL){
                curr->left = new trieNode();
            }
            curr->indexes.push_back(idx);
            curr = curr->left;
        }
        else{
            if(curr->right == NULL){
                curr->right = new trieNode();
            }
            curr->indexes.push_back(idx);
            curr = curr->right;
        }
    }
    curr->indexes.push_back(idx);
    curr->value = n;
}
bool binarySearch(vector<int> &indices,int left,int right){
    int l = 0,r = indices.size()-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(indices[mid]>=left && indices[mid]<=right){
            return true;
        }
        else if(indices[mid]<left){
            l = mid+1;
        }
        else if(indices[mid]>right){
            r = mid-1;
        }
    }
    return false;
}
int maxXor(trieNode *root,int n,int left,int right){
    trieNode *curr = root;
    for(int i=31;i>=0;i--){
        int bit = (n>>i)&1;
        if(bit == 0){
            if(curr->right && binarySearch(curr->right->indexes,left,right)){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        else{
            if(curr->left && binarySearch(curr->left->indexes,left,right)){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
    }
    return curr->value;
}
int main(int argc,char const *argv[]){
    trieNode *head = new trieNode();
    int q;
    cin>>q;
    int idx = 0;
    while(q--){
        int type;
        cin>>type;
        if(type == 0){
            int n;
            cin>>n;
            insertNumber(head,n,idx);
            idx++;
        }
        else{
            int left,right,number;
            cin>>left>>right>>number;
            int ans = maxXor(head,number,left-1,right-1);
            cout<<ans<<endl;
        }
    }
    return 0;
}
