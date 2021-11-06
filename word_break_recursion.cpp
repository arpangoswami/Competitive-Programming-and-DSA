#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool wordSearch(string s, unordered_set<string> &st) {
    if (st.count(s)) {
        return true;
    }
    for (int i = 0; i < s.size(); i++) {
        string sub = s.substr(0, i);
        if (st.count(sub)) {
            bool canSolve = wordSearch(s.substr(i), st);
            if (canSolve) {
                return true;
            }
        }
    }
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> st;
    for (int i = 0; i < wordDict.size(); i++) {
        st.insert(wordDict[i]);
    }
    return wordSearch(s, st);
}
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    while (test--) {
        int num_strings;
        cin >> num_strings;
        vector<string> wordDict(num_strings);
        for (int i = 0; i < num_strings; ++i) {
            cin >> wordDict[i];
        }
        string s;
        cin >> s;
        cout << wordBreak(s, wordDict) << endl;
    }
    return 0;
}