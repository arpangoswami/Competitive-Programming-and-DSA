/*https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/hey-please-help-me/
Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(say a dictionary of words in uppercase and lowercase letters both, words may repeat too). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input(in lowercase only). And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.

INPUT CONSTRAINTS

INPUT FORMAT
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase/uppercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user

OUTPUT FORMAT

If auto - completions exists, output all of them in lexicographical order(lowercase) else output "No suggestions" without quotes

NOTE Auto - completion feature never consider the lowercase/uppercase for suggestions. Query strings are lowercase. Dictionary of words contains both types of cases(Uppercase & Lowercase). Multiple occurrences of word is possible.

SAMPLE INPUT
3
fact
factorial
factory
2
fact
pradyumn
SAMPLE OUTPUT
fact
factorial
factory
No suggestions
Explanation
Already explained above.
*/
#include<iostream>
#include<map>
using namespace std;
class trieNode{
public:
    char data;
    bool terminal;
    map<char,trieNode* > children;
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
        cnt++;
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
        recWordPrint(str,curr);
        return true;
    }
    void recWordPrint(string str,trieNode *curr){
        if(curr->terminal == true){
            cout<<str<<endl;
        }
        for(auto it = curr->children.begin();it!=curr->children.end();it++){
            char ch = it->first;
            trieNode *n = it->second;
            recWordPrint(str+ch,n);
        }
    }
};
int main(void){
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
        bool flag = t.searchWord(str);
        if(!flag){
            t.addWord(str);
            cout<<"No suggestions"<<endl;
        }
    }
}
