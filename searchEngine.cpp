#include<bits/stdc++.h>
using namespace std;
class trieNode{
public:
    int wt;
    char ch;
    unordered_map<char,trieNode* >children;
    bool terminal;
    trieNode(char ch,int w){
        wt = w;
        this->ch = ch;
        terminal = false;
    }
};
void addWord(string s,int weight,trieNode *head){
    trieNode *curr = head;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(curr->children.count(ch) == 0){
            trieNode *n = new trieNode(ch,weight);
            curr->children[ch] = n;
        }
        curr->wt = max(curr->wt,weight);
        curr = curr->children[ch];
        curr->wt = max(curr->wt,weight);
    }
    curr->terminal = true;
}
int searchWeight(string word,trieNode *head){
    trieNode *curr = head;
    int ans = curr->wt;
    for(int i=0;i<word.size();i++){
        char ch = word[i];
        if(curr->children.count(ch) == 0){
            return -1;
        }
        else{
            curr = curr->children[ch];
            ans = curr->wt;
        }
    }
    return ans;
}
int main(void){
    trieNode *root = new trieNode('\0',0);
    int n,q;
    cin>>n>>q;
    while(n--){
        string s;
        int w;
        cin>>s>>w;
        addWord(s,w,root);
    }
    while(q--){
        string s;
        cin>>s;
        cout<<searchWeight(s,root)<<endl;
    }
}
