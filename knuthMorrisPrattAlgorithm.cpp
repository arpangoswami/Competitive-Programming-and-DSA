#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
vector<int> getLPS(string &s){
	int N = s.size();
	vector<int> LPS(N);
	LPS[0] = 0;
	for(int i=1,j=0;i<N;){
		if(s[i] == s[j]){
			LPS[i] = j+1;
			i++;
			j++;
		}else{
			if(j != 0){
				j--;
			}else{
				LPS[i] = 0;
				i++;
			}
		}
	}
	return LPS;
}
bool kmpSearch(string text,string pattern){
	int n = text.size(),m = pattern.size();
	int i,j;
	vector<int> LPS = getLPS(pattern);
	for(i=0,j=0;i<n && j<m;){
		if(text[i] == pattern[j]){
			i++;
			j++;
		}else{
			if(j != 0){
				j = LPS[j-1];
			}else{
				i++;
			}
		}
	}
	if(j == m){
		return true;
	}
	return false;
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	cout<<kmpSearch("ababcabcabababd","ababd")<<"\n";
	cout<<kmpSearch("abcdaba","abcdaa")<<"\n";
	return 0;
}