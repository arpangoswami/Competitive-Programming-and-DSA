#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
/*Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov*/
class trieNode{
public:
    char data;
    bool terminal;
    int cnt;
    unordered_map<char,trieNode* > children;
    trieNode(char ch){
        data = ch;
        terminal = false;
        cnt = 1;
    }
};
void addWord(string str,trieNode *root){
    trieNode *curr = root;
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        if(curr->children.count(ch) == 0){
            trieNode *n = new trieNode(ch);
            curr->children[ch] = n;
        }
        else{
            (curr->children[ch]->cnt)++;
        }
        curr = curr->children[ch];
    }
    curr->terminal = true;
}
string shortestUniquePrefix(string str,trieNode *root){
    trieNode *curr = root;
    string ans;
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        if(curr->children[ch]->cnt == 1){
            ans.push_back(ch);
            return ans;
        }
        else{
            ans.push_back(ch);
            curr = curr->children[ch];
        }
    }
    if(curr->cnt>1){
        ans = "Does not exist";
    }
    return ans;
}
int main(int argc,char const *argv[]){
    int n;
    cin>>n;
    vector<string> input;
    vector<string> shortestUniquePref;
    trieNode *root = new trieNode('\0');
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        input.push_back(str);
        addWord(str,root);
    }
    for(int i=0;i<n;i++){
        string ans = shortestUniquePrefix(input[i],root);
        cout<<input[i]<<" "<<ans<<endl;
        shortestUniquePref.push_back(ans);
    }
    return 0;
}
