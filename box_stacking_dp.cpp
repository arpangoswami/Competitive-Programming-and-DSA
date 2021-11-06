#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct box{
	int l;
	int w;
	int h;
	box(){
		l = -1;
		w = -1;
		h = -1;
	}
	box(int length,int width,int height){
		l = length;
		w = width;
		h = height;
	}
	bool operator < (const box &b1){
		if(l>b1.l){
			return true;
		}else if(w>b1.w){
			return true;
		}
		return false;
	}
};
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int x = 1;
	while(true){
		int n;
		cin>>n;
		if(n == 0){
			break;
		}
		vector<box> available;
		for(int i=0;i<n;i++){
			int length,width,height;
			cin>>length>>width>>height;
			if(width>height){
				swap(height,width);
			}
			box b1 = box(length,width,height);
			box b2 = box(length,height,width);
			box b3 = box(width,height,length);
			available.push_back(b1);
			available.push_back(b2);
			available.push_back(b3);
		}
		sort(available.begin(),available.end());
		for(box x:available){
			cout<<x.l<<" "<<x.w<<" "<<x.h<<endl;
		}
		vector<int> maxHeight(3*n,0);
		for(int i=0;i<(3*n);i++){
			for(int j=0;j<i;j++){
				if(available[j].l > available[i].l && available[j].w > available[i].w){
					maxHeight[i] = max(maxHeight[i],maxHeight[j]+available[i].h);
				}
			}
			if(maxHeight[i] == 0)
				maxHeight[i] = available[i].h;
		}
		int maxm = 0;
		for(int i=0;i<3*n;i++){
			maxm = max(maxm,maxHeight[i]);
		}
		cout<<"Case "<<x<<": maximum height = "<<maxm<<endl;
		x++;
	}
	return 0;
}