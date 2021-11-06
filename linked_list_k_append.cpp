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
	while(test--){
		int n;
		cin >> n;
		int data;
		cin >> data;
		ListNode *head = new ListNode(data);
		ListNode *tail = head;
		for(int i=1;i<n;i++){
			cin >> data;
			tail->next = new ListNode(data);
			tail = tail->next;
		}
		int k;
		cin >> k;
		k %= n;
		if(k == 0){
			printList(head);
			continue;
		}
		ListNode *newHeadPrev = kthNodeFromEnd(k+1,head);
		ListNode *nextNode = newHeadPrev->next;
		newHeadPrev->next = nullptr;
		tail->next = head;
		head = nextNode;
		printList(head);
		cout << "\n";	
	}
	return 0;
}