/*B. Longest Palindrome
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Returning back to problem solving, Gildong is now studying about palindromes. He learned that a palindrome is a string that is the same as its reverse. For example, strings "pop", "noon", "x", and "kkkkkk" are palindromes, while strings "moon", "tv", and "abab" are not. An empty string is also a palindrome.

Gildong loves this concept so much, so he wants to play with it. He has n distinct strings of equal length m. He wants to discard some of the strings (possibly none or all) and reorder the remaining strings so that the concatenation becomes a palindrome. He also wants the palindrome to be as long as possible. Please help him find one.

Input
The first line contains two integers n and m (1≤n≤100, 1≤m≤50) — the number of strings and the length of each string.

Next n lines contain a string of length m each, consisting of lowercase Latin letters only. All strings are distinct.

Output
In the first line, print the length of the longest palindrome string you made.

In the second line, print that palindrome. If there are multiple answers, print any one of them. If the palindrome is empty, print an empty line or don't print this line at all.

Examples

inputCopy
3 3
tab
one
bat
outputCopy
6
tabbat
inputCopy
4 2
oo
ox
xo
xx
outputCopy
6
oxxxxo
inputCopy
3 5
hello
codef
orces
outputCopy
0

inputCopy
9 4
abab
baba
abcd
bcde
cdef
defg
wxyz
zyxw
ijji
outputCopy
20
ababwxyzijjizyxwbaba
Note
In the first example, "battab" is also a valid answer.

In the second example, there can be 4 different valid answers including the sample output. We are not going to provide any hints for what the others are.

In the third example, the empty string is the only valid palindrome string.*/
#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(string s,int m){
    int i = 0;
    while(i<(m/2)){
        if(s[i]!=s[m-i-1]){
            return false;
        }
        i++;
    }
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> arr;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }
    vector<int> pairUp(n,-1);
    for(int i=0;i<n;i++){
        if(pairUp[i]==-1){
            string s = arr[i];
            reverse(s.begin(),s.end());
            for(int j=i+1;j<n;j++){
                if(arr[j] == s){
                    pairUp[j] = i;
                    pairUp[i] = j;
                    break;
                }
            }
        }
    }
    string s1="";
    string s2="";
    string s3="";
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        if(checkPalindrome(arr[i],m) && pairUp[i]==-1){
            s3 = arr[i];
        }
        if(pairUp[i]!=-1 && st.find(i)==st.end()){
            s1 = s1+arr[i];
            s2 = arr[pairUp[i]]+s2;
            st.insert(pairUp[i]);
        }
    }
    string ans = s1+s3+s2;
    cout<<ans.size()<<endl;
    cout<<ans<<endl;
    return 0;
}
