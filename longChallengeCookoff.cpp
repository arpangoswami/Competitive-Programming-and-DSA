#include<bits/stdc++.h>
using namespace std;
bool checkLeap(int year){
    if((year%400)==0) return true;
    if((year%100)==0) return false;
    if((year%4)==0) return true;
    return false;
}
string days[7] = {"thu","fri","sat","sun","mon","tue","wed"};
int main(void){
    int calendar[400]={0};
    int index = 0;
    for(int i=1;i<400;i++){
        if(checkLeap(i)){
            index =(index+2)%7;
        }
        else{
            index = (index+1)%7;
        }
        calendar[i] = calendar[i-1];
        if(checkLeap(i+1)){
            if(days[index]=="sat"){
                calendar[i]++;
            }
        }
        else{
            if(days[index]=="sat"||days[index]=="sun"){
                calendar[i]++;
            }
        }
    }
    int test;
    cin>>test;
    while(test--){
        int m1,y1,m2,y2;
        cin>>m1>>y1>>m2>>y2;
        if(m1<=2){
            y1--;
        }
        if(m2<2){
            y2--;
        }
        int overlap1,overlap2;
        if(y1==1){
            overlap1 = 0;
        }
        else{
           overlap1 = ((y1-1)/400)*101 + calendar[(y1-1)%400];
        }
        if(y2==1){
            overlap2 = 0;
        }
        else{
           overlap2 = ((y2-1)/400)*101 + calendar[(y2-1)%400];
        }
        cout<<overlap2-overlap1<<endl;
    }
}
