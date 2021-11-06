#include<bits/stdc++.h>
using namespace std;
class trieNode{
    public:
    char data;
    unordered_map<char,trieNode*>children;
    bool terminal;
    int cnt = 0;
    trieNode(char ch){
        data = ch;
        terminal = false;
        cnt = 0;
    }
};
void addWord(trieNode* root,string word){
    trieNode* curr = root;
    for(int i=0;i<word.size();i++){
        char ch = word[i];
        if(curr->children.count(ch) == 0){
            trieNode *temp = new trieNode(ch);
            curr->children[ch] = temp;
        }
        curr = curr->children[ch];
        curr->cnt++;
    }
    curr->terminal = true;
}
int prefixContribution(trieNode* root,int group_size){
    if(root == nullptr){
        return 0;
    }
    trieNode* curr = root;
    int ans = (curr->cnt/group_size);
    for(auto it = curr->children.begin();it!=curr->children.end();++it){
        char ch = it->first;
        ans+=prefixContribution(curr->children[ch],group_size);
    }
    return ans;
}
int main(int argc,char const* argv[]){
    int test;
    cin>>test;
    for(int i=1;i<=test;i++){
        int num,group_size;
        cin>>num>>group_size;
        trieNode* root = new trieNode('\0');
        for(int j=0;j<num;j++){
            string s;
            cin>>s;
            addWord(root,s);
        }
        int total_weight = prefixContribution(root,group_size);
        cout<<"Case #"<<i<<": "<<total_weight<<endl;
    }
    return 0;
}