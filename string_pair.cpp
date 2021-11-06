#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
vector<string> single_digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> double_digits = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
vector<string> ten_to_twenty = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
unordered_set<char> st = {'a','e','i','o','u'};
string digit_to_string(int num) {
	string ans = "";
	//cout<<"num: "<<num<<"\n";
	if (num < 10) {
		return single_digits[num%10];
	}
	else if (num >= 10 && num < 20) {
		return ten_to_twenty[num%10];
	}
	else if (num >= 20 && num < 100) {
		if(num%10 == 0){
			return double_digits[num/10];
		}else{
			return double_digits[num/10] + "" + single_digits[num%10];
		}
	} 
	return "hundred";
}
int countVowels(string s){
	int cnt = 0;
	for(char c:s){
		if(st.count(c)){
			cnt++;
		}
	}
	return cnt;
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> arr(n);
	unordered_map<int,int> mp;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mp[arr[i]]++;
	}
	vector<string> text(n);
	int digit_sum = 0;
	for (int i = 0; i < n; i++) {
		text[i] = digit_to_string(arr[i]);
		digit_sum += countVowels(text[i]);
	}
	// for(int i=1;i<=100;i++)
	// 	cout<<digit_to_string(i)<<"\n";
	int pairs = 0;
	for(int i=0;i<n;i++){
		int cmp = digit_sum-arr[i];
		pairs += mp[cmp];
		if(cmp == arr[i]){
			pairs--;
		}
	}
	pairs/=2;
	if(pairs > 100){
		cout<<"greater 100";
	}else{
		string ans = digit_to_string(pairs);
		cout<<ans;
	}
	return 0;
}