#include <bits/stdc++.h>
#define int long long
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(){
		val = -1;
		next = nullptr;
	}
	ListNode(int data){
		val = data;
		next = nullptr;
	}
};
void printList(ListNode *head){
	if(!head){
		return;
	}
	ListNode *curr = head;
	while(curr){
		cout << curr->val << " ";
		curr = curr->next;
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		int n;
		cin >> n;
		int data;
		cin >> data;
		ListNode *head = new ListNode(data), * tail = head;
		for(int i=1;i<n;i++){
			cin >> data;
			tail->next = new ListNode(data);
			tail = tail->next;
		}
		//cout << "yo" << "\n";
		ListNode *headOdd, *headEven;
		ListNode *curr = head;
		bool odd = false,even = false;
		while(curr){
			if(curr->val % 2 == 0 && !even){
				even = true;
				headEven = curr;
			}else if(curr->val % 2 == 1 && !odd){
				odd = true;
				headOdd = curr;
			}
			if(even && odd){
				break;
			}
			curr = curr->next;
		}
		//printList(head);
		if(!even || !odd){
			printList(head);
		}else{
			//cout << headOdd->val << "\n";
			//cout << headEven->val << "\n";
			ListNode *tailOdd = headOdd, *tailEven = headEven;
			curr = head;
			while(curr){
				if(curr == headOdd || curr == headEven){
					curr = curr->next;
					continue;
				}
				if(curr->val % 2 == 0){
					tailEven->next = curr;
					tailEven = tailEven->next;
				}else{
					tailOdd->next = curr;
					tailOdd = tailOdd->next;
				}
				curr = curr->next;
			}
			tailOdd->next = headEven;
			tailEven->next = nullptr;
			printList(headOdd);
		}
		

	}
	return 0;
}