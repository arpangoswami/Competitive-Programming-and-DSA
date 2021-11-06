#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int a,b;
        cin>>a>>b;
        if(a<10 && b<10){
            cout<<a+b<<endl;
            continue;
        }
        if(a%10 == 0 && b%10==0){
            cout<<a+b<<endl;
            continue;
        }
        if(a<10 || b<10){
            if(b<10){
                swap(a,b);
            }
            int cd1 = a+b;
            int b10 = b/10,b1 = b%10;
            int cd2 = b10+((a*10)+b1);
            int cd3 = b1+((b10*10)+a);
            cout<<max(cd1,max(cd2,cd3))<<endl;
            continue;
        }
        int a10 = a/10,a1 = a%10,b10 = b/10,b1 = b%10;
        int cd1 = a+b;
        int cd2 = ((b10*10)+a1)+((a10*10)+b1);
        int cd3 = ((b1*10)+a1)+((b10*10)+a10);
        int cd4 = ((a10*10)+b10)+((a1*10)+b1);
        int cd5 = ((a10*10)+b1)+((b10*10)+a1);
        cout<<max(cd1,max(cd2,max(cd3,max(cd4,cd5))))<<endl;
    }
}
