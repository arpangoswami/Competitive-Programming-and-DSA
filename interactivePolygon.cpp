#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int sides,angle;
        cin>>sides>>angle;
        int centralAngle = ((sides-2)*180)/sides;
        if((angle%centralAngle)!=0){
            cout<<0<<endl;
        }
        else{
            cout<<(angle/centralAngle)+1<<endl;
        }
    }
}
