#include<iostream>
using namespace std;
class Sample{
private:
int s;
public:

    Sample():s(0){}
    Sample(int data):s(data){}
    Sample* operator ->(){
        return this;
    }
    void display(){
        cout<<"Value of Sample is: "<<s<<endl;
    }
};
class Test{
    int data1;
public:
    Test():data1(0){}
    Test(int d1):data1(d1){}
    Test(int d1,int d2):data1(d1+d2){}
    operator Sample(){
        return Sample(data1);
    }
    Test operator()(int x,int y,int z){
        Test tt;
        tt.data1 = x+y+z;
        return tt;
    }
    friend ostream& operator << (ostream &dout,Test &t);
};
ostream & operator << (ostream &dout,Test &t){
        dout<<"Data 1 = "<<t.data1<<endl;
        return dout;
    }
int main(void){
    Sample s1,s2(10);
    Test t1 = 15;
    s1 = t1;
    s1->display();
    Test t2(20,25),t3;
    t3 = t2(15,30,45);
    cout<<t3;
}
