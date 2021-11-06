// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++
 
// Function for finding maximum and value pair
int maxAND (int arr[], int n)
{
    
    // Your code here
    int ans = 0;
    for(int i=31;i>=0;i--){
        int cnt = 0;
        for(int j=0;j<n;j++){
            int pattern = ans | (1 << i);
            if((pattern & arr[j]) == pattern){
                cnt++;
            }
        }
        if(cnt >= 2){
            ans = ans | (1 << i);
        }
    }
    return ans;
    
}

// { Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+5],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        cout <<  maxAND(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends