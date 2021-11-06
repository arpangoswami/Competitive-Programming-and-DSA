#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node(int x){
	    data = x;
	    next = NULL;
	}
};
Node* mergeKLists(Node* arr[], int N);
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
 
typedef pair<int,int> pii;
inline void deleteAndUpdate(Node* arr[],int idx){
    Node *temp = arr[idx];
    Node *t = arr[idx]->next;
    arr[idx] = t;
    delete temp;
}
Node * mergeKLists(Node *arr[], int N){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    if(N == 0){
        return nullptr;
    }
    for(int i=0;i<N;i++){
        if(arr[i]){
            pq.push({t->data,i});
            deleteAndUpdate(arr,i);
        }
    }
    pii p = pq.top();
    int value = p.first,idx = p.second;
    Node *ans = new Node(value),*tail = ans;
    if(arr[idx]){
       int toInsert = arr[idx]->data;
       pq.push({toInsert,idx});
       deleteAndUpdate(arr,idx);
    }
    pq.pop();
    while(!pq.empty()){
        pii p = pq.top();
        pq.pop();
        int value = p.first,idx = p.second;
        Node *temp = new Node(value);
        tail->next = temp;
        if(arr[idx]){
          pq.push({arr[idx]->data,idx});
          deleteAndUpdate(arr,idx);
        }
        tail = tail->next;
    }
    return ans;
}