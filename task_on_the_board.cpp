#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
bool check(int idx,int val,vector<int> &indices){
	int diff = 0;
	for(int x:indices){
		diff+=abs(x-idx);
	}
	return (diff == val);
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;
		int m;
		cin>>m;
		vector<int> diff(m);
		for(int i=0;i<m;i++){
			cin>>diff[i];
		}		
		int n = s.size();
		char arr[m+1];
		for(int i=0;i<m;i++){
			arr[i] = '$';
		}
		arr[m] = '\0';
		unordered_map<char,int> mp;
		set<char,greater<char>> st;
		for(int i=0;i<n;i++){
			mp[s[i]]++;
			st.insert(s[i]);
		}
		auto it = st.begin();
		vector<int> indices;
		for(int i=0;i<m;i++){
			if(diff[i] == 0){
				indices.push_back(i);
			}
		}
		while(mp[*it]<indices.size()){
			it++;
		}
		for(int x:indices){
			arr[x] = *it;
		}
		++it;
		while(it!=st.end()){
			vector<int> temp;
			for(int i=0;i<m;i++){
				if(arr[i] =='$' && check(i,diff[i],indices)){
					temp.push_back(i);
				}
			}
			for(int x:temp){
				indices.push_back(x);
			}
			while(temp.size()>mp[*it]){
				++it;
			}
			for(int x:temp){
				arr[x] = *it;
			}
			++it;
		}
		cout<<arr<<endl;
	}
	return 0;
}