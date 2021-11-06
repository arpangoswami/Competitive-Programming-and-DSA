#include<bits/stdc++.h>
using namespace std;
int f (int n) {
    if (n <= 1) return 1;
    else if (n%2==0)return f(n/2);
    return f(3*n - 1);
}
int main(void){
    cout<<f(20)<<endl;
}
