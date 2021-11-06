#include <bits/stdc++.h>
using namespace std;
vector<int> final(int cars[], int n);
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int i, n;
        cin >> n;
        int cars[n];
        for (i = 0; i < n; i++) {
            cin >> cars[i];
        }
        auto ans = final(cars, n);
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
vector<int> final(int arr[], int n) {
    stack<int> st;
    st.push(arr[0]);
    bool pos;
    for (int i = 1; i < n; i++) {
        pos = st.top() > 0 ? true : false;
        if (pos) {
            if (arr[i] > 0) {
                st.push(arr[i]);
            } else {
                bool toPush = true;
                while (!st.empty() && st.top() > 0) {
                    int val = st.top();
                    if (val > abs(arr[i])) {
                        toPush = false;
                        break;
                    } else if (val < abs(arr[i])) {
                        st.pop();
                    } else {
                        st.pop();
                        toPush = false;
                        break;
                    }
                }
                if (toPush) {
                    st.push(arr[i]);
                }
            }
        } else {
            st.push(arr[i]);
        }
    }
    vector<int> sol;
    while (!st.empty()) {
        int val = st.top();
        sol.push_back(val);
        st.pop();
    }
    reverse(sol.begin(), sol.end());
    return sol;
}
