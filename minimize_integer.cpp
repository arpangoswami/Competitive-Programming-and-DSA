#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        string s;
        cin>>s;
        string odd = "";
        string even ="";
        for(int i=0;i<s.size();i++){
            if(s[i]&1){
                odd+=s[i];
            }
            else{
                even+=s[i];
            }
        }
        string solution = "";
        int i=0,j=0;
        while(i<odd.size() && j<even.size()){
            if(odd[i]<even[j]){
                solution+=odd[i];
                i++;
            }
            else{
                solution+=even[j];
                j++;
            }
        }
        if(i!=odd.size()){
            solution+=odd.substr(i);
        }
        if(j!=even.size()){
            solution+=even.substr(j);
        }
        cout<<solution<<endl;
    }
}
