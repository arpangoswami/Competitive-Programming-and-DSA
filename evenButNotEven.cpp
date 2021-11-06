#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int length;
        cin>>length;
        string even;
        cin>>even;
        bool allEven = true,flag = false;
        int sumOfDigits = 0;
        for(int i=0;i<length;i++){
            sumOfDigits+=(even[i]-48);
            if(even[i]%2!=0){
                allEven = false;
            }
        }
        if(allEven){
            cout<<-1<<endl;
            continue;
        }
        if(!(sumOfDigits&1) && (even[length-1]&1)){
            cout<<even<<endl;
            continue;
        }
        for(int i=(length-1);i>=0;i--){
            if(!(even[i]&1) && !flag){
                sumOfDigits-=(even[i]-48);
                even.pop_back();
            }
            else{
                if(!(sumOfDigits&1)){
                    flag = true;
                    break;
                }
                else{
                    sumOfDigits-=(even[i]-48);
                    even.erase(i,1);
                }
            }
        }
        if(flag){
            cout<<even<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
