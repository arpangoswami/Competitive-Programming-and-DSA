/*Perhaps you have heard of the legend of the Tower of Babylon. Nowadays many details of this tale
have been forgotten. So now, in line with the educational nature of this contest, we will tell you the
whole story:
The babylonians had n types of blocks, and an unlimited supply of blocks of each type.
Each type-i block was a rectangular solid with linear dimensions (xi
, yi
, zi). A block could
be reoriented so that any two of its three dimensions determined the dimensions of the base
and the other dimension was the height.
They wanted to construct the tallest tower possible by stacking blocks. The problem was
that, in building a tower, one block could only be placed on top of another block as long as
the two base dimensions of the upper block were both strictly smaller than the corresponding
base dimensions of the lower block. This meant, for example, that blocks oriented to have
equal-sized bases couldn’t be stacked.
Your job is to write a program that determines the height of the tallest tower the babylonians can
build with a given set of blocks.
Input
The input file will contain one or more test cases. The first line of each test case contains an integer n,
representing the number of different blocks in the following data set. The maximum value for n is 30.
Each of the next n lines contains three integers representing the values xi
, yi and zi
.
Input is terminated by a value of zero (0) for n.
Output
For each test case, print one line containing the case number (they are numbered sequentially starting
from 1) and the height of the tallest possible tower in the format
‘Case case: maximum height = height’
Sample Input
1
10 20 30
2
6 8 10
5 5 5
7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0
Sample Output
Case 1: maximum height = 40
Case 2: maximum height = 21
Case 3: maximum height = 28
Case 4: maximum height = 342
*/
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
		cout<<"Case "<<x<<": maximum height = "<<maxm<<endl;
		x++;
	}
	return 0;
}