/*
Playlist
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.

What is the longest sequence of successive songs where each song is unique?

Input

The first input line contains an integer n: the number of songs.

The next line has n integers k1,k2,…,kn: the id number of each song.

Output

Print the length of the longest sequence of unique songs.

Constraints
1≤n≤2⋅105
1≤ki≤109
Example

Input:
8
1 2 1 3 2 7 4 2

Output:
5
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	map<int,int> mp;
	int i=0;
	int maxLen = 1;
	for(int j=0;j<n;j++){
		mp[arr[j]]++;
		while(mp[arr[j]] == 2){
			mp[arr[i]]--;
			i++;
		}
		maxLen = max(j-i+1,maxLen);
	}
	cout<<maxLen<<"\n";
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