#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<int> num;
void pre(){
	int i=0;
	while(num.size() < 1000){
		i++;
		if(i % 3 == 0 || i % 10 == 3){
			continue;
		}
		num.push_back(i);
	}
}
void solveQuestion(){
	int k;
	cin >> k;
	cout << num[k-1] << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	pre();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}