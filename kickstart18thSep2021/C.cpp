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
typedef long double ld;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
const int MX = 2e5;

typedef pair<char,int> pci;
string getLargestString(string s,int k){
	vector<int> frequency(26,0);
	for(char c:s){
		frequency[c-'a']++;
	}
	priority_queue<pci> pq;
	for(int i=0;i<26;i++){
		if(frequency[i] > 0){
			pq.push({'a'+i,frequency[i]});
		}
	}
	int consecutiveLast = 0;
	char lastPickedCharacter = '$';
	string ans;
	while(!pq.empty()){
		char letter = pq.top().first;
		int times = pq.top().second;
		pq.pop();
		if(lastPickedCharacter != letter){
			ans.push_back(letter);
			consecutiveLast = 1;
			lastPickedCharacter = letter;
			if(times > 1){
				pq.push({letter,times-1});
			}
		}else{
			if(consecutiveLast >= k && !pq.empty()){
				char next = pq.top().first;
				int nextFre = pq.top().second;
				pq.pop();
				ans.push_back(next);
				consecutiveLast = 1;
				lastPickedCharacter = next;
				if(nextFre > 1){
					pq.push({next,nextFre-1});
				}
				pq.push({letter,times});
			}else if(consecutiveLast < k){
				consecutiveLast++;
				ans.push_back(letter);
				if(times > 1){
					pq.push({letter,times-1});
				}
			}
		}
	}
	return ans;
}
typedef long long ll;
long countMoves(vector<int> numbers){
	ll minm = *min_element(numbers.begin(),numbers.end());
	ll ans = 0;
	for(ll x:numbers){
		ans += (x - minm);
	}
	return ans;
}
vector<long> countSentences(vector<string> wordSet,vector<string> sentences){
	map<string,int> mp;
	for(string x:wordSet){
		sort(x.begin(),x.end());
		mp[x]++;
	}
	vector<long> ans(sentences.size(),1LL);
	for(int i=0;i<sentences.size();i++){
		istringstream iss(sentences[i]);
		string s;
		while(iss >> s){
			sort(s.begin(),s.end());
			ans[i] *= mp[s];
		}
	}
	return ans;
}

int segment(int x,vector<int> spaces){
	deque<int> indexes;
	for(int i=0;i<x;i++){
		while(!indexes.empty() && spaces[i] <= spaces[indexes.back()]){
			indexes.pop_back();
		}
		indexes.push_back(i);
	}
	int ans = INT_MIN;
	for(int i=x;i<spaces.size();i++){
		ans = max(ans,spaces[indexes.front()]);
		while(!indexes.empty() && (i-x) >= indexes.front()){
			indexes.pop_front();
		}
		while(!indexes.empty() && spaces[i] <= spaces[indexes.back()]){
			indexes.pop_back();
		}
		indexes.push_back(i);
	}
	ans = max(ans,spaces[indexes.front()]);
	return ans;
}



void solveQuestion(){
	// string s;
	// int k;
	// cin >> s >> k;
	// cout<<getLargestString(s,k)<<"\n";
	cout<<segment(2,{8,2,4,6})<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}