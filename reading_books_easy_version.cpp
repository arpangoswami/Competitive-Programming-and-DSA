#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxN = 2e5;
struct book{
	ll time;
	int alice;
	int bob;
	book(){
		time = 0;
		alice = 0;
		bob = 0;
	}
	book(ll tm,int al,int bb){
		time = tm;
		alice = al;
		bob = bb;
	}
};
bool cmp(const book &b1,const book &b2){
	return b1.time < b2.time;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<book> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].time>>arr[i].alice>>arr[i].bob;
	}
	sort(arr.begin(),arr.end(),cmp);
	vector<book> all;
	vector<book> alc;
	vector<book> bb;
	for(int i=0;i<n;i++){
		if(arr[i].alice == 1 && arr[i].bob == 1){
			all.push_back(arr[i]);
		}else if(arr[i].alice == 1 && arr[i].bob == 0){
			alc.push_back(arr[i]);
		}else if(arr[i].alice == 0 && arr[i].bob == 1){
			bb.push_back(arr[i]);
		}
	}
	bool flag = true;
	if(all.size() + alc.size() < k){
		flag = false;
	}
	if(all.size() + bb.size() < k){
		flag = false;
	}
	if(!flag){
		cout<<-1<<endl;
	}else{
		ll req1 = k,req2 = k;
		int i = 0,j = 0;k = 0;
		ll sum = 0;
		for(;i<all.size() && j<alc.size() && k<bb.size() && req1 > 0 && req2 > 0;){
			if(all[i].time < (alc[j].time + bb[k].time)){
				sum+=all[i].time;
				i++;
				req1--;
				req2--;
			}else{
				sum+=alc[j].time;
				sum+=bb[k].time;
				j++;
				k++;
				req1--;
				req2--;
			}
		}
		if(j == alc.size() || k == bb.size()){
			while(req1 > 0){
				sum+=all[i].time;
				i++;
				req1--;
				req2--;
			}
		}
		if(i == all.size()){
			while(req1 > 0){
				sum+=alc[j].time;
				j++;
				sum+=bb[k].time;
				k++;
				req1--;
				req2--;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}