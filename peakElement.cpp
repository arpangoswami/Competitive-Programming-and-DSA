// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
int peakElement(int arr[], int n)
{
   // Your code here
   if(n==1) return arr[0];
   if(n==2){
       if(arr[0]>=arr[1]){
           return 0;
       }
       return 1;
   }
   cout<<"b"<<endl;
   if(arr[0]>=arr[1]) return 0;
   if(arr[n-1]>=arr[n-1]) return n-1;
   int low = 0,high = n-1;
   cout<<low<<" "<<high<<endl;
   while(low<=high){
       int mid = (low+high)/2;
       if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1]){
           cout<<mid<<endl;
           return mid;
       }
       else if(arr[mid]<arr[mid+1]){
            cout<<"yo1"<<endl;
           low = mid+1;
       }
       else{
           cout<<"yo2"<<endl;
           high = mid-1;
       }
   }
   return -1;
}

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		//cout<<"a"<<endl;
		int A = peakElement(a,n);

		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;

		cout<<f<<endl;

	}

	return 0;
}  // } Driver Code Ends
