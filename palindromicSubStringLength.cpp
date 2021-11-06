#include<bits/stdc++.h>
using namespace std;
bool primeSieve(int n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        string s;
        cin>>s;
        int curr_length = 1,max_length = 1,n = s.size();
        for(int i=0;i<n;i++){
            int left = i,right = i;
            while(left>=0 && right<n && s[left] == s[right]){
                curr_length = right-left+1;
                max_length = max(max_length,curr_length);
                left--;
                right++;
            }
            left = i,right = i+1;
            while(left>=0 && right<n && s[left] == s[right]){
                curr_length = right-left+1;
                max_length = max(max_length,curr_length);
                left--;
                right++;
            }
        }
        if(primeSieve(max_length)){
            cout<<"PRIME"<<endl;
        }
        else{
            cout<<"NOT PRIME"<<endl;
        }
    }
}
