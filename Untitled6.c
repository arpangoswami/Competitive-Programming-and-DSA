#include<iostream>
#include<unordered_map>
using namespace std;
class trieNode{
public:
    char data;
    bool terminal;
    unordered_map<data,trieNode* > children;
    trieNode(char data){
        this->data = data;
        this->terminal = false;
    }
};
class Trie{
public:
    Node *root;
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
