#include<bits/stdc++.h>
using namespace std;
class Triplet{
public:
    int x;
    int y;
    int gcd;
};
Triplet extendedEuclid(int a,int b){
    if(b==0){
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
        Triplet smallAns = extendedEuclid(b,a%b);
        Triplet ans;
        ans.x = smallAns.y;
        ans.y = smallAns.x - (a/b)*smallAns.y;
        ans.gcd = smallAns.gcd;
        return ans;

}
int moduloinverse(int a,int b){
    int x = extendedEuclid(a,b).x;
    return (x%b + b)%b;
}
int main(void){
    int a = 5;
    int b = 17;
    Triplet ans;
    /*if(a>b){
        ans = extendedEuclid(a,b);
        cout<<ans.gcd<<endl;
        cout<<ans.x<<endl;
        cout<<ans.y<<endl;
    }
    else{
        ans = extendedEuclid(b,a);
        cout<<ans.gcd<<endl;
        cout<<ans.y<<endl;
        cout<<ans.x<<endl;
    }*/
    cout<<moduloinverse(a,b)<<endl;
}
