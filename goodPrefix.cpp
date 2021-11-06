#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int freq[26]={0};
        string s;
        cin>>s;
        int k,x;
        cin>>k>>x;
        int length = 0;
        for(int i=0;i<s.size();i++){
            if(freq[s[i]-97] == x && k == 0){
                break;
            }
            else if(freq[s[i]-97] == x && k>0){
                k--;
            }
            else if(freq[s[i]-97]<x){
                length++;
                freq[s[i]-97]++;
            }
        }
        cout<<length<<endl;
    }
}
