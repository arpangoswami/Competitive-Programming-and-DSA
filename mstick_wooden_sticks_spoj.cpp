/*
https://www.spoj.com/problems/MSTICK/
There is a pile of  n  wooden sticks. The length and weight of each stick
are known in advance. The sticks are to be processed by a woodworking machine
in one by one fashion. It needs some time, called setup time, for the  machine
to  prepare  processing  a  stick.  The  setup  times  are  associated  with
cleaning  operations  and changing tools and shapes in the machine. The setup
times of the woodworking machine are given as follows: 
 
(a) The setup time for the first wooden stick is 1 minute. 
(b) Right after processing a stick of length  l  and weight  w , the machine will
need no setup time for a stick of length  l'  and weight  w'  if  l ≤ l' and  w ≤ w'. 
Otherwise, it will need 1 minute for setup. 
 
You are to find the minimum setup time to process a given pile of  n  wooden sticks. 
For example, if you have five sticks whose pairs of length and weight are  
( 9 , 4 ) , ( 2 , 5 ) , ( 1 , 2 ) , ( 5 , 3 ) , and ( 4 , 1 ) , then the minimum
setup time should be 2 minutes since there is a sequence of pairs ( 4 , 1 ) , 
( 5 , 3 ) , ( 9 , 4 ) , ( 1 , 2 ) , ( 2 , 5 ) .
Input
The input consists of T test cases. The number of test cases (T) is given 
in the first line of the input file. Each test case consists of two lines:
 The first line has an integer n , 1 <= n <= 5000 , that represents the number 
of wooden sticks in the test case, and the second line contains 2n positive
integers l1 , w1 , l2 , w2 ,..., ln , wn , each of magnitude at most 10000 ,
where li and wi are the length and weight of the i th wooden stick, respectively.
The 2n integers are delimited by one or more spaces.

SAMPLE INPUT
3 
5 
4 9 5 2 2 1 3 5 1 4 
3 
2 2 1 1 2 2 
3 
1 3 2 2 3 1 

Output
 
The output should contain the minimum setup time in minutes, one per line. 

SAMPLE OUTPUT
2
1
3

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct stick{
	int length,weight;
};
bool compare(const stick &s1,const stick &s2){
	if(s1.length == s2.length){
		return s1.weight>s2.weight;
	}
	return s1.length>s2.length;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<stick> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i].length>>arr[i].weight;
		}
		sort(arr.begin(),arr.end(),compare);
		vector<int> tail;
		tail.push_back(arr[0].weight);
		for(int i=1;i<n;i++){
			if(arr[i].weight>tail.back()){
				tail.push_back(arr[i].weight);
			}else{
				int idx = lower_bound(tail.begin(),tail.end(),arr[i].weight) - tail.begin();
				tail[idx] = arr[i].weight;
			}
		}
		cout<<tail.size()<<"\n";
	}
	return 0;
}