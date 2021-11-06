#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int x,y;
	cin >> x >> y;
	string s;
	cin >> s;
	int up = 0,down = 0,left = 0,right = 0,X = 0,Y = 0;
	bool f = false;
	if(x == X && y == Y){
		cout<<"YES"<<'\n';
		return;
	}
	for(char c:s){
		if(c == 'U'){
			up++;
			Y++;
		}else if(c == 'D'){
			down++;
			Y--;
		}else if(c == 'L'){
			left++;
			X--;
		}else{
			right++;
			X++;
		}
		if(X == x && Y == y){
			cout<<"YES"<<'\n';
			return;
		}
		int xShift = X - x,yShift = Y - y;
		if(xShift >= 0 && yShift >= 0 && up >= yShift && right >= xShift){
			cout<<"YES"<<"\n";
			return;
		}else if(xShift >= 0 && yShift <= 0 && down >= abs(yShift) && right >= xShift){
			cout<<"YES"<<"\n";
			return;
		}else if(xShift <= 0 && yShift >= 0 && up >= yShift && left >= abs(xShift)) {
			cout<<"YES"<<"\n";
			return;
		}else if(xShift <= 0 && yShift <= 0 && down >= abs(yShift) && left >= abs(xShift)){
			cout<<"YES"<<"\n";
			return;
		}
	}
	cout<<"NO"<<'\n';
	return;

}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}