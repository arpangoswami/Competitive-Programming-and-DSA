#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	cout<<3*n + 4<<endl;
	int x = 0,y = 0;
	cout<<x<<" "<<y<<endl;
	cout<<x+1<<" "<<y<<endl;
	x++;
	y++;
	for(int i=0;i<n;i++){
		cout<<x<<" "<<y<<endl;
		cout<<x-1<<" "<<y<<endl;
		cout<<x+1<<" "<<y<<endl;
		x++;
		y++;
	}
	cout<<x<<" "<<y<<endl;
	cout<<x-1<<" "<<y<<endl;
	return 0;
}