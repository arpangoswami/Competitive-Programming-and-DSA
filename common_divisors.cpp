#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool checkDiv(vector<int> &arr1,vector<int> &arr2){
	int idx = -1;
	for(int i=0;i<26;i++){
		if(arr2[i]!=0){
			idx = i;
			break;
		}
	}
	if(arr1[idx] == 0){
		return false;
	}
	if(arr2[idx]%arr1[idx]!=0){
		return false;
	}
	int factor = ((arr2[idx])/(arr1[idx]));
	for(int i=0;i<26;i++){
		if(arr1[i]*factor!=arr2[i]){
			return false;
		}
	}
	return true;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string a,b;
	cin >> a >> b;
	int n = a.size(),m = b.size();
	vector<int> string1(26,0),string2(26,0),window1(26,0),window2(26,0);
	for(int i=0;i<n;i++){
		string1[a[i] - 'a']++;
	}
	for(int i=0;i<m;i++){
		string2[b[i] - 'a']++;
	}
	unordered_set<string> st1,st2;
	for(int i=0;i<n;i++){
		window1[a[i]-'a']++;
		if(checkDiv(window1,string1)){
			st1.insert(a.substr(0,i+1));
		}
	}
	for(int i=0;i<m;i++){
		window2[b[i]-'a']++;
		if(checkDiv(window2,string2)){
			st2.insert(b.substr(0,i+1));
		}
	}
	int cnt = 0;
	for(string x:st1){
		//cout<<x<<"\n";
		if(st2.count(x)){
			cnt++;
		}
	}
	cout<<cnt<<"\n";
	return 0;
}