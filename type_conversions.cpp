#include<iostream>
#include<cstdlib>
using namespace std;
class INT{
        public:
        int t;
        INT(){t=0;}
        INT(int a){t=a;}
        INT operator = (const INT &t1)
        {
        if(this != &t1)
           t = t1.t;
        return t;
        }
        INT operator ++()
        {
        INT temp;
        temp.t = ++t;
        return temp;
        }
        INT operator ++(int)
        {
        INT temp;
        temp.t = t++;
        return temp;
        }
        operator int ()
        {
           return t;
        }
};
int main(){
        int x = 3;
        INT y = x;
        y++ = ++y;
        cout<<x<<" "<<y.t<<endl;
        x = y;
        cout<<x<<" "<<y.t;
        return 0;
}
