/*
Digit Pairs
Problem Description
Given N three-digit numbers, your task is to find bit score of all N numbers and then print the number of pairs possible based on these calculated bit score.

1. Rule for calculating bit score from three digit number:

From the 3-digit number,

· extract largest digit and multiply by 11 then

· extract smallest digit multiply by 7 then

· add both the result for getting bit pairs.

Note: - Bit score should be of 2-digits, if above results in a 3-digit bit score, simply ignore most significant digit.

Consider following examples:

Say, number is 286

Largest digit is 8 and smallest digit is 2

So, 8*11+2*7 =102 so ignore most significant bit , So bit score = 02.

Say, Number is 123

Largest digit is 3 and smallest digit is 1

So, 3*11+7*1=40, so bit score is 40.

2. Rules for making pairs from above calculated bit scores

Condition for making pairs are

· Both bit scores should be in either odd position or even position to be eligible to form a pair.

· Pairs can be only made if most significant digit are same and at most two pair can be made for a given significant digit.

Constraints
N<=500

Input Format
First line contains an integer N, denoting the count of numbers.

Second line contains N 3-digit integers delimited by space

Output
One integer value denoting the number of bit pairs.

Timeout
1

Explanation
Example 1

Input

8 234 567 321 345 123 110 767 111

Output

3

Explanation

After getting the most and least significant digits of the numbers and applying the formula given in Rule 1 we get the bit scores of the numbers as:

58 12 40 76 40 11 19 18

No. of pair possible are 3:

40 appears twice at odd-indices 3 and 5 respectively. Hence, this is one pair.

12, 11, 18 are at even-indices. Hence, two pairs are possible from these three-bit scores.

Hence total pairs possible is 3
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int bitScore(int n){
	int largest = n%10,smallest = n%10;
	int temp = n;
	while(temp > 0){
		int dig = temp%10;
		largest = max(largest,dig);
		smallest = min(smallest,dig);
		temp/=10;
	}
	return ((largest*11) + (smallest*7))%100;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	unordered_map<int,int> even;
	unordered_map<int,int> odd;
	for(int i=0;i<n;i++){
		int bs = bitScore(arr[i]);
		if(i%2 == 0){
			even[bs/10]++;
		}else{
			odd[bs/10]++;
		}
	}
	int ans = 0;
	for(int i=0;i<=9;i++){
		int num1 = even[i];
		int num2 = odd[i];
		int possible = (num1 * (num1-1))/2;
		possible+=(num2 * (num2-1))/2;
		ans+=min(2LL,possible);
	}
	cout<<ans;
	return 0;
}