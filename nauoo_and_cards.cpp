/*
A. Nauuo and Cards
time limit per test1.5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Nauuo is a girl who loves playing cards.

One day she was playing cards but found that the cards were mixed with some empty ones.

There are n cards numbered from 1 to n, and they were mixed with another n empty cards. She piled up the 2n cards and drew n of them. The n cards in Nauuo's hands are given. The remaining n cards in the pile are also given in the order from top to bottom.

In one operation she can choose a card in her hands and play it — put it at the bottom of the pile, then draw the top card from the pile.

Nauuo wants to make the n numbered cards piled up in increasing order (the i-th card in the pile from top to bottom is the card i) as quickly as possible. Can you tell her the minimum number of operations?

Input
The first line contains a single integer n (1≤n≤2⋅105) — the number of numbered cards.

The second line contains n integers a1,a2,…,an (0≤ai≤n) — the initial cards in Nauuo's hands. 0 represents an empty card.

The third line contains n integers b1,b2,…,bn (0≤bi≤n) — the initial cards in the pile, given in order from top to bottom. 0 represents an empty card.

It is guaranteed that each number from 1 to n appears exactly once, either in a1..n or b1..n.

Output
The output contains a single integer — the minimum number of operations to make the n numbered cards piled up in increasing order.

Examples
inputCopy
3
0 2 0
3 0 1
outputCopy
2
inputCopy
3
0 2 0
1 0 3
outputCopy
4
inputCopy
11
0 0 0 5 0 0 0 4 0 0 11
9 2 6 0 8 1 7 0 3 0 10
outputCopy
18
Note
Example 1

We can play the card 2 and draw the card 3 in the first operation. After that, we have [0,3,0] in hands and the cards in the pile are [0,1,2] from top to bottom.

Then, we play the card 3 in the second operation. The cards in the pile are [1,2,3], in which the cards are piled up in increasing order.

Example 2

Play an empty card and draw the card 1, then play 1, 2, 3 in order.


*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
void answer(vector<int> &pile) {
	int ans = pile.size(),n = pile.size();
	for (int i = 0; i < n; i++) {
		int pos = i + 1;
		if (pile[i] != 0) {
			ans = max(ans, pos - pile[i] + n + 1);
		}
	}
	cout << ans;
}
void solveQuestion() {
	int n;
	cin >> n;
	vector<int> hand(n);
	vector<int> pile(n);
	for (int &i : hand) {
		cin >> i;
	}
	int oneIndex = -1;
	for (int i = 0; i < n; i++) {
		cin >> pile[i];
		if (pile[i] == 1) {
			oneIndex = i;
		}
	}
	if (oneIndex == -1) {
		answer(pile);
		return;
	}
	bool flag = true;
	for (int i = oneIndex + 1; i < n; i++) {
		if (pile[i] - pile[i - 1] != 1) {
			flag = false;
		}
	}
	int required = pile.back() + 1;
	unordered_set<int> st;
	for(int i:hand){
		if(i!=0){
			st.insert(i);
		}
	}
	int idx = 0;
	for(int i=required;i<=n;i++){
		if(st.count(required) == 0){
			flag = false;
			break;
		}
		if(pile[idx]!=0){
			st.insert(pile[idx]);
		}
		idx++;
		required++;
	}
	if (flag) {
		//cout<<"yolo"<<"\n";
		cout<<oneIndex;
		return;
	}
	answer(pile);
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}