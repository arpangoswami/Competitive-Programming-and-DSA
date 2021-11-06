#include<bits/stdc++.h>
using namespace std;
int main(){
    long n;
    cin>>n;
    long sum3 = 0,sum5 = 0,sum15 = 0;
    long terms3 = 0,terms5 = 0,terms15 = 0;
    terms3 = (n-1)/3;
    terms5 = (n-1)/5;
    terms15 = (n-1)/15;
    sum3 = ((terms3)*(6+(terms3-1)*3))/2;
    sum5 = ((terms5)*(10+(terms5-1)*5))/2;
    sum15 = ((terms15)*(30+(terms15-1)*15))/2;
    cout<<(sum3+sum5-sum15)<<endl;
    return 0;
}
