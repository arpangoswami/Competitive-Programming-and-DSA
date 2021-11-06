/*Local King
Problem
Submissions
Leaderboard
Discussions
In a far land there exists N Kings . But there are only K thrones . So there will be a contest for the thrones.

K is always less than N.

So there is a contest between all the kings from index i to index i+N-K and a king whose strength is maximum is selected , this goes on for K times until K kings are selected.

Now you are given the strength of all the kings . In a contest the king with maximum power wins.

Now, return the power of K kings who wins the K thrones.

A King can occupy more than one throne.

Input Format

The first line contains an integer t , number of testcase
The each testcase contains a integer n and k
The next line contains n space separated integers .
Constraints

1<=t<=10
1<=n<=10^6
1<=a[i]<=10^9
Output Format

print the ans of each testcase , space separated K integers

Sample Input 0

1
5 3
1 2 3 4 5
Sample Output 0

3 4 5 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin >> n >> k;
		k = (n-k+1);
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		deque<int> Q(k);
		for(int i=0;i<k;i++){
			while(!Q.empty() && arr[i] >= arr[Q.back()]){
				Q.pop_back();
			}
			Q.push_back(i);
		}
		for(int i=k;i<n;i++){
			cout << arr[Q.front()] <<" ";
			while(!Q.empty() && (i-k) >= Q.front()){
				Q.pop_front();
			}
			while(!Q.empty() && arr[i] >= arr[Q.back()]){
				Q.pop_back();
			}
			Q.push_back(i);
		}
		cout << arr[Q.front()] <<"\n";
	}
	return 0;
}