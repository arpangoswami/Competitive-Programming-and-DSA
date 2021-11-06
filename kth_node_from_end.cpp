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
ListNode *kthNodeFromEnd(int k,ListNode *head){
	ListNode *fast = head, *slow = head;
	int cnt = 0;
	while(cnt < k){
		fast = fast->next;
		cnt++;
	}
	while(fast){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		int data;
		cin >> data;
		ListNode *head = new ListNode(data);
		if(data == -1){
			delete head;
			break;
		}
		ListNode *tail = head;
		while(true){
			cin >> data;
			if(data == -1){
				break;
			}
			tail->next = new ListNode(data);
			tail = tail->next;
		}
		int k;
		cin >> k;
		ListNode *temp = kthNodeFromEnd(k,head);
		cout << temp->val << "\n";
	}
	return 0;
}