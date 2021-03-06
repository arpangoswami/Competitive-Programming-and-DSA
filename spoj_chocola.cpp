/*
CHOCOLA - Chocolate
no tags 
We are given a bar of chocolate composed of m*n square pieces. One should break the chocolate into single squares. Parts of the chocolate may be broken along the vertical and horizontal lines as indicated by the broken lines in the picture.

A single break of a part of the chocolate along a chosen vertical or horizontal line divides that part into two smaller ones. Each break of a part of the chocolate is charged a cost expressed by a positive integer. This cost does not depend on the size of the part that is being broken but only depends on the line the break goes along. Let us denote the costs of breaking along consecutive vertical lines with x1, x2, ..., xm-1 and along horizontal lines with y1, y2, ..., yn-1.

The cost of breaking the whole bar into single squares is the sum of the successive breaks. One should compute the minimal cost of breaking the whole chocolate into single squares.


For example, if we break the chocolate presented in the picture first along the horizontal lines, and next each obtained part along vertical lines then the cost of that breaking will be y1+y2+y3+4*(x1+x2+x3+x4+x5).

Task
Write a program that for each test case:

Reads the numbers x1, x2, ..., xm-1 and y1, y2, ..., yn-1
Computes the minimal cost of breaking the whole chocolate into single squares, writes the result.
Input
One integer in the first line, stating the number of test cases, followed by a blank line. There will be not more than 20 tests.

For each test case, at the first line there are two positive integers m and n separated by a single space, 2 <= m,n <= 1000. In the successive m-1 lines there are numbers x1, x2, ..., xm-1, one per line, 1 <= xi <= 1000. In the successive n-1 lines there are numbers y1, y2, ..., yn-1, one per line, 1 <= yi <= 1000.

The test cases will be separated by a single blank line.

Output
For each test case : write one integer - the minimal cost of breaking the whole chocolate into single squares.

Example
Input:
1

6 4
2
1
3
1
4
4
1
2

Output:
42

*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int m,n;
	cin >> m >> n;
	vector<int> arr1(m-1);
	vector<int> arr2(n-1);
	for(int i=0;i<(m-1);i++){
		cin >> arr1[i];
	}
	for(int i=0;i<(n-1);i++){
		cin >> arr2[i];
	}
	sort(arr1.begin(),arr1.end(),greater<int>());
	sort(arr2.begin(),arr2.end(),greater<int>());
	int i = 0,j = 0;
	int hor = 1,ver = 1,ans = 0;
	while(i < (m-1) && j < (n-1)){
		if(arr1[i] > arr2[j]){
			ans += arr1[i] * ver;
			hor++;
			i++;
		}else{
			ans += arr2[j] * hor;
			ver++;
			j++;
		}
	}
	while(i < (m-1)){
		ans += arr1[i] * hor;
		i++;
	}
	while(j < (n-1)){
		ans += arr2[j] * ver;
		j++;
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}