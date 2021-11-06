#include <bits/stdc++.h>
using namespace std;
void dequeSlidingWindow(int arr[], int n, int k)
{
    deque<int> DQ(k);
    int i;
    for (i = 0; i < k; ++i) {
        while ((!DQ.empty()) && arr[i] >= arr[DQ.back()])
            DQ.pop_back();
        DQ.push_back(i);
    }
    for (; i < n; ++i) {
        cout << arr[DQ.front()] << " ";
        while ((!DQ.empty()) && DQ.front() <= i - k)
            DQ.pop_front();
        while ((!DQ.empty()) && arr[i] >= arr[DQ.back()])
            DQ.pop_back();
        DQ.push_back(i);
    }
    cout << arr[DQ.front()];
}
int main()
{
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        dequeSlidingWindow(arr,n,k);
        cout<<endl;
    }
    return 0;
}
