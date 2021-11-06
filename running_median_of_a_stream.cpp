#include <bits/stdc++.h>
using namespace std;
void addNumber(int x,priority_queue<int>&max_heap,priority_queue<int,vector<int>,greater<int>> &min_heap,int median){
    if(max_heap.size() == 0 && min_heap.size() == 0){
        max_heap.push(x);
        return;
    }
    if(x >= median){
        min_heap.push(x);
        return;
    }
    if(x<median){
        max_heap.push(x);
        return;
    }
}
void balanceHeaps(priority_queue<int> &max_heap,priority_queue<int,vector<int>,greater<int>> &min_heap){
    int sz1 = max_heap.size(),sz2 = min_heap.size();
    if(sz1 == sz2 || sz1 == sz2 + 1 || sz1 + 1 == sz2){
        return;
    }
    if(sz1 > sz2 + 1){
        int val = max_heap.top();
        max_heap.pop();
        min_heap.push(val);
    }
    else{
        int val = min_heap.top();
        min_heap.pop();
        max_heap.push(val);
    }
}
int findMedian(priority_queue<int>&max_heap,priority_queue<int,vector<int>,greater<int>> &min_heap){
    if(max_heap.size() == min_heap.size()){
        return (max_heap.top() + min_heap.top())/2;
    }
    else if(max_heap.size() > min_heap.size()){
        return max_heap.top();
    }
    return min_heap.top();
}
int main() {
    /* code here */
    int test;
    cin>>test;
    while(test--){
        priority_queue<int> max_heap;
        priority_queue<int,vector<int>,greater<int> >min_heap;
        int n;
        cin>>n;
        int median = 0;
        while(n--){
            int x;
            cin>>x;
            addNumber(x,max_heap,min_heap,median);
            balanceHeaps(max_heap,min_heap);
            median = findMedian(max_heap,min_heap);
            cout<<median<<" ";
        }
        cout<<endl;
     }

    return 0;
}