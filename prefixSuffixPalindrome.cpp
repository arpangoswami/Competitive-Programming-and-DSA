#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s){
    int n = s.size();
    for(int i=0;i<(n/2);i++){
        if(s[i]!=s[n-i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        string s;
        cin>>s;
        int maxLength = 1,n = s.size();
        string ans = "";
        ans+=s[0];
        //if(isPalindrome(s)){
            //cout<<s<<endl;
          //  continue;
        //}
        /*for(int i=0;i<=n;i++){
            string a1 = s.substr(0,i);
            if(isPalindrome(a1) && maxLength<a1.size()){
                ans = a1;
                maxLength = a1.size();
            }
            for(int j=(n-1);j>=i;j--){
                string a2 = s.substr(j);
                string temp = a1+a2;
                //cout<<i<<" "<<j<<" "<<temp.size()<<" "<<temp<<endl;
                if(isPalindrome(temp) && maxLength<temp.size()){
                    ans = temp;
                    maxLength = temp.size();
                }
            }
        }*/
        //if(isPalindrome(s)){
          //  cout<<s<<endl;
            //continue;
        //}
        //string rev = s;
        //reverse(rev.begin(),rev.end());
        for(int i=0;i<=n;i++){
            string temp = s.substr(0,i);
            if(isPalindrome(temp) && temp.size()>maxLength){
                maxLength = temp.size();
                ans = temp;
            }
            temp = s.substr(i);
            if(isPalindrome(temp) && temp.size()>maxLength){
                maxLength = temp.size();
                ans = temp;
            }
        }
        unordered_set<string> st1,st2;
        for(int i=0;i<=n;i++){
            st1.insert(s.substr(0,i));
            st2.insert(s.substr(i));
        }
        for(auto i=st1.begin();i!=st.end();i++){
            string temp = *i;
            for(int j=0;j<=temp.size();j++){
                string a3 = temp.substr(j);
                string a4 = temp.substr(0,j);
                if(isPalindrome(a3)){
                    string cd = a1+a4;
                    if(st2.find(a4)!=st2.end() && cd.size()<=n){
                        if(cd.size()>maxLength){
                            ans = cd;
                            maxLength = cd.size();
                        }
                    }
                }
            }
        }
        for(auto i=st2.begin();i)
        cout<<ans<<endl;
    }
    return 0;
}
