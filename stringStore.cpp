#include<iostream>
#include<unordered_map>
using namespace std;
class trieNode{
public:
    char data;
    bool terminal;
    unordered_map<char,trieNode* > children;
    trieNode(char ch){
        data = ch;
        terminal = false;
    }
};
class Trie{
public:
    trieNode *root;
    int cnt;
    Trie(){
        root = new trieNode('\0');
        cnt = 0;
    }
    void addWord(string str){
        trieNode *curr = root;
        for(int i=0;i<str.size();i++){
            char ch = str[i];
            if(curr->children.count(ch) == 0){ //If character not present create an entry
                trieNode *n = new trieNode(ch);
                curr->children[ch] = n;
            }
            curr = curr->children[ch]; // traverse to the child
        }
        curr->terminal = true;
    }
    bool searchWord(string str){
        trieNode *curr = root;
        for(int i=0;i<str.size();i++){
            char ch = str[i];
            if(curr->children.count(ch) == 0){
                return false;
            }
            else{
                curr = curr->children[ch];
            }
        }
        return curr->terminal;
    }
};
int main(int argc,char const *argv[]){
    Trie t;
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        t.addWord(str);
    }
    int q;
    cin>>q;
    while(q--){
        string str;
        cin>>str;
        cout<<t.searchWord(str)<<endl;
    }
    return 0;
}
