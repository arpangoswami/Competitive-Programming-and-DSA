#include<bits/stdc++.h>
using namespace std;
bool compare(int arr1[],int arr2[]){
    for(int i=0;i<26;i++){
        if(arr1[i]!=arr2[i]){
            return false;
        }
    }
    return true;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int left,right;
        int arr1[26]={0},arr2[26]={0};
        bool flag = true;
        if(n%2 == 1){
            for(int i=0;i<n;i++){
                arr1[s[i]-97]++;
            }
            int f = 0;
            char c;
            for(int i=0;i<26;i++){
                if(arr1[i]%2==1){
                    f++;
                    c = (char)(97+i);
                }
            }
            if(f>=2 || f==0){
                flag = false;
                cout<<"NO"<<endl;
                continue;
            }
            if(s[n/2 + 1] == c){
                swap(s[n/2+1],s[n/2]);
            }
            if(s[n/2 - 1] == c){
                swap(s[n/2-1],s[n/2]);
            }
            left = n/2 - 1,right = n/2 + 1;
            for(int i=0;i<26;i++){
                arr1[i] = 0;
            }
        }
        else{
            left = n/2 - 1,right = n/2;
        }
        while(left>=0 && right<n){
            if(s[left]==s[right]){
                arr1[left--]++;
                arr2[right++]++;
            }
            else{
                if(left==0){
                    flag = false;
                    break;
                }
                arr1[left-1]++;
                arr2[right+1]++;
                arr1[left]++;
                arr2[right]++;
                if(compare(arr1,arr2)){
                    flag = false;
                    break;
                }
                left-=2;
                right+=2;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
