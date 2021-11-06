/*
Having several accounts on several servers one has to remember many passwords. You can imagine a
situation when someone forgets one of them. He/she remembers only that it consisted of words x, y
and z as well as two digits: one at the very beginning and the other one at the end of the password.
Your task is to write a program which will generate all possible password on the basis of given
dictionary and set of rules. For the example given above the dictionary contains three words: x, y, z,
and the rule is given as ‘0#0’ what stands for < digit >< word_from_the_dictionary >< digit >.
Input
First line contains a number of words in the dictionary (n). The words themselves are given in n
consecutive lines. The next line contains number of rules (m). Similarly consecutive m lines contain
rules. Each rule consists of characters ‘#’ and ‘0’ given in arbitrary order. The character ‘#’ stands for
word from the dictionary whilst the character ‘0’ stands for a digit.
Input data may contain many sets of dictionaries with rules attached to them.
Output
For each set ‘dictionary + rules’ you should output two hyphens followed by a linebreak and all matching
passwords given in consecutive lines. Passwords should be sorted by rules what means that first all
passwords matching the first rule and all words must be given, followed by passwords matching the
second rule and all words, etc. Within set of passwords matching a word and a rule an ascending digit
order must be preserved.
Assumptions: A number of words in the dictionary is greater than 0 and smaller or equal to 100
(0 < n ≤ 100). Length of the word is greater than 0 and smaller than 256. A word may contain
characters ‘A’..‘Z’,‘a’..‘z’,‘0’..‘9’.A number of rules is smaller that 1000, and a rule is shorter that 256
characters. A character ‘0’ may occur in the rule no more than 7 times, but it has to occur at least
once. The character ‘#’ is not mandatory meaning there can be so such characters in the rule or not.
Sample Input
2
root
2super
1
#0
1
admin
1
#0#
Sample Output
--
root0
root1
root2
root3
root4
root5
root6
root7
root8
root9
2super0
2super1
2super2
2super3
2super4
2super5
2super6
2super7
2super8
2super9
--
admin0admin
admin1admin
admin2admin
admin3admin
admin4admin
admin5admin
admin6admin
admin7admin
admin8admin
admin9admin
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
void allPwds(string &rule,int idx,string ans,vector<string> &words){
	if(idx == rule.size()){
		cout<<ans<<"\n";
		return;
	}
	if(rule[idx] == '#'){
		for(string x:words){
			allPwds(rule,idx+1,ans+x,words);
		}
	}else{
		for(int i=0;i<=9;++i){
			char c = i + '0';
			allPwds(rule,idx+1,ans+c,words);
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	while(cin>>n){
		cout<<"--"<<"\n";
		vector<string> words(n);
		for(int i=0;i<n;i++){
			cin>>words[i];
		}
		int m;
		cin>>m;
		vector<string> rules(m);
		for(int i=0;i<m;i++){
			cin>>rules[i];
		}
		for(int i=0;i<m;i++){
			string ans = "";
			allPwds(rules[i],0,ans,words);
		}
	}
	return 0;
}