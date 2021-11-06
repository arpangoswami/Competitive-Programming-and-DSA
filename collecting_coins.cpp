#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,n;
        cin>>a>>b>>c>>n;
        if((a+b+c+n)%3==0){
            int ran[3] = {a,b,c};
            sort(ran,ran+3);
            if(n>=((ran[2]-ran[0])+(ran[2]-ran[1]))){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
