#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:2000000")
#define int long long
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() {
		val = -1;
		next = nullptr;
	}
	ListNode(int d) {
		val = d;
		next = nullptr;
	}
};
void printList(ListNode *head) {
	if (!head) {
		return;
	}
	cout << head->val << " ";
	printList(head->next);
}
ListNode* merge(ListNode* head1, ListNode* head2) {
	ListNode *head3;
	if (head1->val < head2->val) {
		head3 = head1;
		head1 = head1->next;
	} else {
		head3 = head2;
		head2 = head2->next;
	}
	ListNode *curr = head3;
	while (head1 && head2) {
		if (head1->val < head2->val) {
			curr->next = head1;
			head1 = head1->next;
		} else {
			curr->next = head2;
			head2 = head2->next;
		}
		curr = curr->next;
	}
	if (!head1) {
		curr->next = head2;
	} else {
		curr->next = head1;
	}
	return head3;
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n1;
		cin >> n1;
		int data;
		cin >> data;
		ListNode *head1 = new ListNode(data);
		ListNode *tail1 = head1;
		n1--;
		while (n1--) {
			cin >> data;
			tail1->next = new ListNode(data);
			tail1 = tail1->next;
		}
		int n2;
		cin >> n2;
		cin >> data;
		ListNode *head2 = new ListNode(data);
		ListNode *tail2 = head2;
		n2--;
		while (n2--) {
			cin >> data;
			tail2->next = new ListNode(data);
			tail2 = tail2->next;
		}
		ListNode *head3 = merge(head1, head2);
		ListNode *curr = head3;
		printList(curr);
		cout << "\n";
		while (head3 != nullptr) {
			ListNode *temp = head3;
			head3 = head3->next;
			delete temp;
		}
	}
	return 0;
}