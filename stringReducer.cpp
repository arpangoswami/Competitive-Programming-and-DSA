#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	string s;
	cin >> s;
	int left = 0,right = s.size() - 1;
	if(s.size() <= 1){
		cout<<s.size()<<"\n";
		return;
	}
	while(left < right && s[left] == s[right]){
		char c = s[left];
		while(left < right && s[left] == c){
			left++;
		}
		while(right > left && s[right] == c){
			right--;
		}
	}
	cout<<"right: "<<right<<" left: "<<left<<"\n";
	cout << (right - left + 1) << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}