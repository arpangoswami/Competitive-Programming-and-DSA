#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
struct Node{
	int data;
	Node* next;
};
char FindThirdLastConsonant(char str[]){
	unordered_set<char> vowels;
	vowels.insert('a');
	vowels.insert('e');
	vowels.insert('i');
	vowels.insert('o');
	vowels.insert('u');
	vowels.insert('A');
	vowels.insert('E');
	vowels.insert('I');
	vowels.insert('O');
	vowels.insert('U');
	int len = 0;
	while(str[len] != '\0'){
		len++;
	}
	int cons = 0;
	for(int i=(len-1);i>=0;i--){
		if(!vowels.count(str[i])){
			if(cons == 2){
				return str[i];
			}else{
				cons++;
			}
		}
	}
	return 'b';
}
Node* MoveNodes(Node* head,int x){
	vector<Node*> less;
	vector<Node*> great;
	Node* itr = head;
	while(itr){
		if((itr->data) < x){
			less.push_back(itr->data);
		}else{
			great.push_back(itr->data);
		}
		itr = itr->next;
	}
	Node* headPtr = nullptr;
	if(less.size() > 0){
		headPtr = new Node();
		headPtr->data = less[0];
		headPtr->next = nullptr;
	}else if(great.size() > 0){
		headPtr = new Node();
		headPtr->data = great[0];
		headPtr->next = nullptr;
	}else{
		return nullptr;
	}
	Node *tail = headPtr;
	for(int i=1;i<less.size();i++){
		tail->next = new Node();
		tail = tail->next;
		tail->data = less[i];
		tail->next = nullptr;
	}
	int st = 0;
	if(less.size() == 0){
		st++;
	}
	for(int i=st;i<great.size();i++){
		tail->next = new Node();
		tail = tail->next;
		tail->data = great[i];
		tail->next = nullptr;
	}
	return headPtr;
}
int32_t main(int32_t argc, char const *argv[])
{
	char str[10000];
	cin >> str;
	cout << FindThirdLastConsonant(str) << "\n";
	Node* head = new Node
}