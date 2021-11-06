#include <iostream>
using namespace std;
 int subseq(string q, string ans) {
		if (q.length() == 0) {
			return 1;
		}
		char ch = q[0];
		return subseq(q.substr(1), ans)+subseq(q.substr(1), ans + ch);
	}
void printsubseq(string q, string ans) {
		if (q.size() == 0) {
			cout<<ans<<" ";
			return;
		}
		printsubseq(q.substr(1), ans);
		printsubseq(q.substr(1), ans + q[0]);
	}
int main() {
    string a;
    cin>>a;
    printsubseq(a,"");
    cout<<endl;
    cout<<subseq(a,"");
    return 0;
}
