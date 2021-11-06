#include<iostream>
using namespace std;
class Index{
private:
    int ind;
public:
    Index():ind(0){}
    Index(int i):ind(i){}
    Index operator + (const Index &I){
        return Index(ind+I.ind);
    }
    operator int() const
    {
        return ind;
    }
    int getdata(){
        return ind;
    }
    void display(){
        cout<<"Value of Index is "<<ind<<" "<<endl;
    }
};
class Integer{
private:
    int inte;
public:
    Integer():inte(0){}
    Integer(Index &I):inte(I.getdata()){}
    void display(){
        cout<<"Value of Integer is "<<inte<<" "<<endl;
    }
};

int main(void){
    Index in(4), out(10);
    int x = in;
    cout<<x<<endl;
    int y = in + out;
    cout<<y<<endl;
    in = 2;
    Integer i;
    i = in;
    i.display();
    in.display();
    out.display();

}
