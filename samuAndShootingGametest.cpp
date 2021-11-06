#include<bits/stdc++.h>
using namespace std;
bool shootingGame(int p1,int p2,int coins,int pW,int prob1,int prob2,int &probTillNow){

}
int main(){
    int test;
    cin>>test;
    while(test--){
        int points1,points2,coins,minPoints,p1,p2;
        cin>>points1>>points2>>coins>>minPoints>>p1>>p2;
        double prob1,prob2;
        prob1 = ((double)p1/100);
        prob2 = ((double)p2/100);
        double probTillNow = 0;
        bool flag = shootingGame(points1,points2,coins,minPoints,prob1,prob2,probTillNow);
        cout<<probTillNow<<endl;
    }
    return 0;
}
