/*
Paint the walls Problem Code: PATWALL
Add problem to Todo list
Submit

 
Chef has decided to paint all the n walls (numbered from 1 to n) of his house. The i-th wall has a value ei associated with it.

Chef will always choose some consecutive segment (exactly one segment) of the walls to paint. Suppose, he decided to paint k consecutive walls, i.e.e that segment has exactly k walls. Then, the effort required to paint the i-th wall, individually, will be ei+i⋅k. For example, suppose the Chef decides to paint 3 walls: the 5th, 6th and 7th walls. Then the total effort needed would be (e5+5⋅3)+(e6+6⋅3)+(e7+7⋅3).

Now Chef can only put the total s amount of effort and would like to paint as many walls as possible. Can you tell the maximum number of walls he can paint?

Input
The first line of the input contains two space-separated integers n,s denoting the total number of walls and the maximum total effort Chef can put in painting the walls.
The second line contains n space separated denoting the array e.
Output
Print the maximum number of walls that Chef can paint.
Constraints
1≤n≤105
1≤s≤1018
1≤ei≤106
Information to Score Partial Points
For 30% of the score, it is guaranteed that n≤1000
For the remaining 70%: No extra constraints.
Sample Input
4 5
2 1 3 4
Sample Output
1
Explanation
In the given input he can just paint the first wall since 2+1⋅1=3 which is less than 5 hence answer is 1.

He could also paint just the second wall since 1+2⋅1=3 which is less than 5.

But he cannot paint both the first and second walls, because then the total effort needed would be (2+1⋅2)+(1+2⋅2)=9, which is more than 5.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool check(int size,vector<int> &prefix,int n,int effortMax){
	for(int i=0;i<=(n-size);i++){
		int sub = (i == 0) ? 0 : prefix[i-1];
		int add = prefix[i+size-1];
		int effort = add-sub;
		sub = ((i*(i+1))/2) * size;
		add = (((i+size)*(i+size+1))/2) * size;
		effort += (add-size);
		if(effort <= effortMax){
			return true;
		}
	}
	return false;
}
void solveQuestion(){
	int n,effort;
	cin >> n >> effort;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	vector<int> prefix(n);
	prefix[0] = arr[0];
	for(int i=1;i<n;i++){
		prefix[i] = prefix[i-1] + arr[i];
	}
	int low = 1,high = n;
	int ans = 0;
	while(low <= high){
		int mid = (low + high)/2;
		if(check(mid,prefix,n,effort)){
			ans = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}