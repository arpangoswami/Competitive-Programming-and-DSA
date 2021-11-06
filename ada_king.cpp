#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<vector<char>> board(8,vector<char>(8,'X'));
		board[0][0] = 'O';
		n--;
		int i = 0,j = 1;
		while(n > 0){
			board[i][j++] = '.';
			if(j == 8){
				i++;
				j = 0;
			}
			n--;
		}
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cout<<board[i][j];
			}
			cout<<"\n";
		}
	}
	return 0;
}