#include <bits/stdc++.h>
#define int long long
using namespace std;
struct List{
	int val;
	List *next;
	List(int x):val(x),next(nullptr){

	}
};
List* insertBeg(List *head,int x){
	List *temp = new List(x);
	temp->next = head;
	return temp;
}
void display(List *head){
	List *curr = head;
	while(curr){
		cout<<curr->val<<" ";
		curr = curr->next;
	}
	cout<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	List *head = nullptr;
	while(cin >> n){
		head =  insertBeg(head,n);
	}
	display(head);
	return 0;
}