#include<bits/stdc++.h>
using namespace std;
class trieNode{
public:
    trieNode **children;
    int weight;
    trieNode(){
        children = new trieNode *[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        weight = 0;
    }
};
void insert_s(string s,int weight,trieNode *root){
    if(s.empty()){
        return;
    }
    int index = s[0] - 'a';
    trieNode *child;
    if(root->children[index]){
        child = root->children[index];
    }
    else{
        child = new trieNode();
        root->children[index] = child;
    }
    if(root->weight<weight){
        root->weight = weight;
    }
    insert_s(s.substr(1),weight,child);
}
int searchBest(string s,trieNode *root){
    int bestWeight = -1;
    trieNode *current = root;
    for(int i=0;i<s.length();i++){
            int index = s[i] - 'a';
            trieNode *child = current->children[index];
            if(child){
                current = child;
                bestWeight = child->weight;
            }
            else{
                return -1;
            }
        }
        return bestWeight;
}

int main(void){
    int n,q;
    cin>>n>>q;
    trieNode *root = new trieNode();
    for(int i=0;i<n;i++){
        string s;
        int weight;
        cin>>s>>weight;
        insert_s(s,weight,root);
    }
    for(int i=0;i<q;i++){
        string pre;
        cin>>pre;
        cout<<searchBest(pre,root)<<endl;
    }
}
