#include<iostream>
using namespace std;
class Source{
    int x;
public:
    Source(int x){
        this->x = x;
    }
    void disp(){
        cout<<x<<endl;
    }
    int get(){
        return x;
    }
};
class Dest{
    int y;
public:
    Dest():y(0){}
    /*Dest(Source &s){
        y = s.get();
    }*/
    Dest operator = (Source &s){
        y = s.get();
    }
    void display(){
        cout<<y<<endl;
    }
};
int main(void){
    Source s(10);
    Dest d;
    d = s;
    s = d;
    d.display();
    s.disp();
}
