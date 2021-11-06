#include <bits/stdc++.h> 
using namespace std; 
int *st; 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 
int findGcd(int ss, int se, int qs, int qe, int si) 
{ 
    if (ss>qe || se < qs) 
        return 0; 
    if (qs<=ss && qe>=se) 
        return st[si]; 
    int mid = ss+(se-ss)/2; 
    return gcd(findGcd(ss, mid, qs, qe, si*2+1),findGcd(mid+1, se, qs, qe, si*2+2)); 
} 
int findRangeGcd(int ss, int se, int arr[],int n) 
{ 
    if (ss<0 || se > n-1 || ss>se) 
    { 
        return -1; 
    } 
    return findGcd(0, n-1, ss, se, 0); 
} 
int constructST(int arr[], int ss, int se, int si) 
{ 
    if (ss==se) 
    { 
        st[si] = arr[ss]; 
        return st[si]; 
    } 
    int mid = ss+(se-ss)/2; 
    st[si] = gcd(constructST(arr, ss, mid, si*2+1),constructST(arr, mid+1, se, si*2+2)); 
    return st[si]; 
} 
int *constructSegmentTree(int arr[], int n) 
{ 
int height = (int)(ceil(log2(n))); 
int size = 2*(int)pow(2, height)-1; 
st = new int[size]; 
constructST(arr, 0, n-1, 0); 
return st; 
} 
int main() 
{ 
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++)
       cin>>arr[i];
      constructSegmentTree(arr, n); 
      int q;
      cin>>q;
      while(q--)
      {
        int l,r;
        cin>>l>>r;
         l-=1;
         r -=1;
        cout << findRangeGcd(l, r, arr, n) << "\n"; 
      }
  }
    return 0; 
} 