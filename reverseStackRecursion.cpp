#include<iostream>
#include<stack>
using namespace std;
void reverseStack(stack<int> &s,stack<int> &t,int n){
    if(n>0){
        t.push(s.top());
        s.pop();
        reverseStack(s,t,n-1);
    }
    else return;
}
int main() {
    int n;
    cin>>n;
    stack<int> s,temp;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        s.push(temp);
    }
    reverseStack(s,temp,n);
    while(!temp.empty()){
        cout<<temp.top()<<endl;
        temp.pop();
    }
	return 0;
}
