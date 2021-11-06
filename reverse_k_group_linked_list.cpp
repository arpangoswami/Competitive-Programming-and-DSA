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
	ListNode(int d){
		val = d;
		next = nullptr;
	}
};
ListNode* reverseKgroups(ListNode *head,int k){
	ListNode *temp = nullptr, *prev = nullptr, *curr = head;
	int cnt = 0;
	while(cnt < k){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		cnt++;
	}
	if(temp){
		ListNode *shead = reverseKgroups(temp,k);
		head->next = shead;
	}
	return prev;
}
void printList(ListNode *head){
	if(!head){
		return;
	}
	cout<<head->val<<" ";
	printList(head->next);
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin >> n >> k;
	int data;
	cin >> data;
	ListNode *head = new ListNode(data);
	ListNode *tail = head;
	n--;
	while(n--){
		cin >> data;
		tail->next = new ListNode(data);
		tail = tail->next;
	}
	head = reverseKGroups(head,k);
	printList(head);
	return 0;
}