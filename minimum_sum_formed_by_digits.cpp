/*Min sum formed by digitsSubmissions: 10331   Accuracy: 50.81%   Difficulty: Easy   Marks: 2

Problems
Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array. All digits of given array must be used to form the two numbers.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Next line of each test contains N space seperated integers denoting the elements of the array.
Output:

For each test case output a single line containing the required sum.
Constraints:

1<=T<=100
1<=N<=50
Example:

Input

2
6
6 8 4 5 2 3
5
5 3 0 7 4

Output

604
82

Explanation:

Test Case 1-

The minimum sum is formed by numbers
358 and 246
Test Case 2 -

The minimum sum is formed by numbers
35 and 047
** For More Input/Output Examples Use 'Expected Output' option ***/
#include <bits/stdc++.h>
using namespace std;
void sum_ar(int *result,int *arr1,int *arr2,int size,int s){
    int carry = 0;
    for(int i=size-1;i>=0;i--){
        result[i+1] = (carry+arr1[i]+arr2[i])%10;
        carry = (carry+arr1[i]+arr2[i])/10;
    }
    if(carry){
        result[0] = carry;
        cout<<result[0];
    }
    for(int i=1;i<s;i++){
        cout<<result[i];
    }
}
void digitarray(int *pr1,int i,int *pr2,int j,priority_queue<int,vector<int>,greater<int>>&pq){
    while(!pq.empty()){
        pr1[i++] = pq.top();
        pq.pop();
        pr2[j++] = pq.top();
        pq.pop();
    }
}
int main() {
	//code
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    vector<int> arr(n,0);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
	    while(pq.top()==0){
	        pq.pop();
	        n--;
	    }
	    int *arr1 = new int[(n+1)/2]();
	    int *arr2 = new int[(n+1)/2]();
	    int *result = new int[((n+1)/2+1)]();
	    if(n%2){
	        arr1[0] = pq.top();
	        pq.pop();
	        digitarray(arr2,1,arr1,1,pq);
	    }
	    else{
	        digitarray(arr1,0,arr2,0,pq);
	    }
	    sum_ar(result,arr1,arr2,(n+1)/2,((n+1)/2+1));
	    cout<<endl;
	    delete []arr1;
	    delete []arr2;
	    delete []result;
	}
	return 0;
}
