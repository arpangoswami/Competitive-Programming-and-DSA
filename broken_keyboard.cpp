#include<bits/stdc++.h>
using namespace std;
int cal_length(const string &subs){
    int i=0;
    int length = 1;
    while(subs[i+1] == subs[i]){
        length++;
        i++;
    }
    return length;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        string s;
        cin>>s;
        bool *correct = new bool [26]();
        int i = 0;
        while(i<s.size()){
            int length = cal_length(s.substr(i));
            if(length&1){
                correct[s[i]-97] = true;
            }
            i+=length;
        }
        string ans="";
        for(int i=0;i<26;i++){
            if(correct[i]){
                char c = i+97;
                ans+=c;
            }
        }
        cout<<ans<<endl;
        delete []correct;
    }
}
