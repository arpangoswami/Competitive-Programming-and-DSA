/*
A. Déjà Vu
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A palindrome is a string that reads the same backward as forward. For example, the strings "z",
 "aaa", "aba", and "abccba" are palindromes, but "codeforces" and "ab" are not. You hate palindromes because they give you déjà vu.

There is a string s. You must insert exactly one character 'a' somewhere in s.
 If it is possible to create a string that is not a palindrome, you should find one example. Otherwise, you should report that it is impossible.

For example, suppose s= "cbabc". By inserting an 'a', you can create "acbabc",
 "cababc", "cbaabc", "cbabac", or "cbabca". However "cbaabc" is a palindrome, so you must output one of the other options.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The only line of each test case contains a string s consisting of lowercase English letters.

The total length of all strings does not exceed 3⋅105.

Output
For each test case, if there is no solution, output "NO".

Otherwise, output "YES" followed by your constructed string of length |s|+1 on the next line. If there are multiple solutions, you may print any.

You can print each letter of "YES" and "NO" in any case (upper or lower).

Example
inputCopy
6
cbabc
ab
zza
ba
a
nutforajaroftuna
outputCopy
YES
cbabac
YES
aab
YES
zaza
YES
baa
NO
YES
nutforajarofatuna
Note
The first test case is described in the statement.

In the second test case, we can make either "aab" or "aba". But "aba" is a palindrome, so "aab" is the only correct answer.

In the third test case, "zaza" and "zzaa" are correct answers, but not "azza".

In the fourth test case, "baa" is the only correct answer.

In the fifth test case, we can only make "aa", which is a palindrome. So the answer is "NO".

In the sixth test case, "anutforajaroftuna" is a palindrome, but inserting 'a' elsewhere is valid.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void shiftRight(vector<char> &shift,int i){
	for(int j=shift.size()-2;j>=i;j--){
		shift[j+1] = shift[j];
	}
	shift[i] = 'a';
}
void solveQuestion(){
	string s;
	cin >> s;
	int firstNonA = -1;
	int n = s.size();
	for(int i=0;i<n;i++){
		if(s[i] != 'a'){
			firstNonA = i;
			break;
		}
	}
	if(firstNonA == -1){
		cout<<"NO"<<'\n';
		return;
	}
	vector<char> shift(n+1);
	for(int i=0;i<n;i++){
		shift[i] = s[i];
	}
	int altPos = (n-firstNonA);
	shiftRight(shift,altPos);
	cout<<"YES"<<"\n";
	for(char c:shift){
		cout<<c;
	}
	cout<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}