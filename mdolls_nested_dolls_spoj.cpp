#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct dolls{
	int height;
	int width;
};
bool compare(const dolls &d1,const dolls &d2){
	if(d1.width == d2.width){
		return d1.height>d2.height;
	}
	return d1.width<d2.width;
}
int ceilIdx(int num,vector<int> &tail){
	int left = 0,right = tail.size()-1;
	while(left<right){
		int mid = left + (right-left)/2;
		if(tail[mid]<num){
			right = mid;
		}
		else{
			left = mid+1;
		}
	}
	return right;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int m;
		cin>>m;
		vector<dolls> input(m);
		for(int i=0;i<m;i++){
			cin>>input[i].width>>input[i].height;
		}
		sort(input.begin(),input.end(),compare);
		vector<int> sequence(m);
		for(int i=0;i<m;++i){
			sequence[i] = input[i].height;
		}
		vector<int> tail;
		tail.push_back(sequence[0]);
		for(int i=1;i<m;i++){
			if(sequence[i]<=tail.back()){
				tail.push_back(sequence[i]);
			}
			else{
				int idx = ceilIdx(sequence[i],tail);
				tail[idx] = sequence[i];
			}
		}
		cout<<tail.size()<<"\n";
	}
	return 0;
}