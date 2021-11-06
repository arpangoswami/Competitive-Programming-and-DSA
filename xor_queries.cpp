/*
You are given a task to handle  queries. In each query, you will be given three positive integers . You have to choose a number  that lies in the interval [] such that  is maximum, where  denotes the bitwise xor operation. Can you find the maximum value of ?

Input Format

The first line contains a single positive integer  denoting the total number of queries. Each of the next  lines contains three space separated positive integers  denoting the values of  and  respectively.

Constraints

for 15% of the score, 
for the other 15% of the score, 
Output Format

For each query, print the maximum value of  in a newline.

Sample Input 0

5
2 1 10
3 5 6
6 3 10
4 2 8
7 10 15
Sample Output 0

11
6
15
12
13
Explanation 0

Query : If we choose , then , is the maximum value over all  [].

Query : If we choose , then , is the maximum value over all  [].

Query : If we choose , then , is the maximum value over all  [].

Query : If we choose , then , is the maximum value over all  [].

Query : If we choose , then , is the maximum value over all  [].
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int x,left,right;
	cin >> x >> left >> right;
	int ans = 0;
	bool small = false,large = false;
	for(int i=30;i>=0;i--){
		int bit = (x >> i) & 1;
		int lbit = (left >> i) & 1;
		int rbit = (right >> i) & 1;
		if(bit == 0){
			if(rbit || large){
				ans += (1 << i);
				if(lbit == 0){
					small = true;
				}
			}
		}else if(bit == 1){
			if(lbit == 0 || small == true){
				if(rbit == 1){
					large = true;
				}
			}else{
				ans += (1 << i);
			}
		}
	}
	cout<<(ans ^ x)<< "\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}