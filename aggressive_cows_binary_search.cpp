/*AGGRCOW - Aggressive cows
#binary-search
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
#include<bits/stdc++.h>
using namespace std;
bool check(int cows, long long positions[], int n, long long difference){
    int number=1;
    long long last_position=positions[0];
    for(int i=1; i<n ; i++){
        if(positions[i]>=(difference+last_position)){
            last_position=positions[i];
            number++;
        }
        if(number==cows){
            return true;
        }
    }
    return false;
}
int main(void)
{
    int test;
    cin >> test;
    while(test--)
    {
       int n,c;
       cin >> n,c;
       long long p[n];
       for(int i=0;i<n;i++){
        cin >> p[i];
       }
       sort(p,p+n);
       long long start=0,finish=p[n-1]-p[0],ans=-1;
       while(start<=finish){
            long long mid=start+(finish-start)/2;
            if(check(c,p,n,mid)){
                ans=mid;
                start=mid+1;
            }
            else{
                finish=mid-1;
            }

       }
       cout << ans <<endl;
    }
}


*/
#include<bits/stdc++.h>
using namespace std;
bool dist(long mid,long *arr,unsigned n,int co){
    int cows = 1;
    int index = 0;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[index]>=mid){
            cows++;
            index = i;
        }
        if(cows == co){
            return true;
        }
    }
    return false;
}
int main(void){

        long n;
        int cows;
        cin>>n>>cows;
        long *arr = new long[n];
        for(unsigned i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        long low = 0,high = arr[n-1]-arr[0],ans = 0;
        while(low<=high){
            long mid = (low+high)/2;
            if(dist(mid,arr,n,cows)){
                low = mid+1;
                ans = mid;
            }
            else{
                high = mid-1;
            }
        }
        cout<<ans<<endl;
        delete []arr;

}
