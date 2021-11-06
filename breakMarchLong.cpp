#include<bits/stdc++.h>
using namespace std;
int main(){
    int test,subtask;
    cin>>test>>subtask;
    if(subtask == 1){
        while(test--){
            int n;
            cin>>n;
            int *a = new int[n];
            int *b = new int[n];
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            for(int i=0;i<n;i++){
                cin>>b[i];
            }
            unordered_set<int> s;
            sort(a,a+n);
            sort(b,b+n);
            bool flag = true;
            if(a[0]>=b[0]){
                flag = false;
            }
            else{
                s.insert(a[0]);
                s.insert(b[0]);
            }
            for(int i=1;i<n && flag;i++){
                if(s.find(a[i])!=s.end() && a[i]<b[i]){
                    s.insert(a[i]);
                    s.insert(b[i]);
                }
                else{
                    flag = false;
                }
            }
            if(flag){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
            delete []a;
            delete []b;
        }
    }
    else{
        while(test--){
            int n;
            cin>>n;
            int *a = new int[n];
            int *b = new int[n];
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            for(int i=0;i<n;i++){
                cin>>b[i];
            }
            delete []a;
            delete []b;
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
