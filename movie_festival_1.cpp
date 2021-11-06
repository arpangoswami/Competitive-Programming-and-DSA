/*
Movie Festival
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?

Input

The first input line has an integer n: the number of movies.

After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.

Output

Print one integer: the maximum number of movies.

Constraints
1≤n≤2⋅105
1≤a<b≤109
Example

Input:
3
3 5
4 9
5 8

Output:
2
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool cmp(pii &p1,pii &p2){
	if(p1.second == p2.second){
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<pii> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(),arr.end(),cmp);
	int ans = 0;
	int finTime = 0;
	for(int i=0;i<n;i++){
		if(arr[i].first >= finTime){
			finTime = arr[i].second;
			ans++;
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