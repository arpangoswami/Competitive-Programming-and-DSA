/*BABTWR - Tower of Babylon
no tags 
Apart from the Hanging Gardens the Babylonians (around 3000-539 b.c.) built the Tower of Babylon as well. The tower was meant to reach the sky, but the project failed because of a confusion of language imposed from much higher above.

For the 2638th anniversary a model of the tower will be rebuilt. n different types of blocks are available. Each one of them may be duplicated as many times as you like. Each type has a height y, a width x and a depth z. The blocks are to be stacked one upon eachother so that the resulting tower is as high as possible. Of course the blocks can be rotated as desired before stacking. However for reasons of stability a block can only be stacked upon another if both of its baselines are shorter.

Input
The number of types of blocks n is located in the first line of each test case. On the subsequent n lines the height yi, the width xi and the depth zi of each type of blocks are given. There are never more than 30 different types available.

There are many test cases, which come one by one. Input terminates with n = 0.

Edited: You can assume that max(xi, yi, zi) <= 2500.

Output
For each test case your program should output one line with the height of the highest possible tower.

Example
Sample input:
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
1
1 1 1
0

Sample output:
342
1*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
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
	box(int height,int length,int width){
		l = length;
		w = width;
		h = height;
		if(w>l){
			swap(w,l);
		}
	}
};
bool compare(const box &b1,const box &b2){
	ll area1 = 1LL * b1.l * b1.w;
	ll area2 = 1LL * b2.l * b2.w;
	return area1>area2;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
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
			box b1 = box(height,width,length);
			box b2 = box(length,height,width);
			box b3 = box(width,height,length);
			available.push_back(b1);
			available.push_back(b2);
			available.push_back(b3);
		}
		n = 3*n;
		sort(available.begin(),available.end(),compare);
		vector<int> maxHeight(n,0);
		maxHeight[0] = available[0].h;
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(available[j].l > available[i].l && available[j].w > available[i].w){
					maxHeight[i] = max(maxHeight[i],maxHeight[j]+available[i].h);
				}
			}
			if(maxHeight[i] == 0)
				maxHeight[i] = available[i].h;
		}
		int maxm = 0;
		for(int i=0;i<n;i++){
			maxm = max(maxm,maxHeight[i]);
		}
		cout<<maxm<<endl;
	}
	return 0;
}