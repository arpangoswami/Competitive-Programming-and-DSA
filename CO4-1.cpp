#include<iostream>
using namespace std;
class Sample{
private:
    int data;
public:
    Sample():data(0){}
    Sample(int d):data(d){}
    int operator ++(){
        return (++data);
    }
    int operator +(int s){
        return (data + s);
    }
    operator int(){
        return data;
    }
    void display(){
        cout<<data<<endl;
    }
};
int main(void){
    Sample s1(15),s2,s3(10);
    s2 = s1 + (++s3);
    s2.display();
    s3.display();
    s1 = s3 + 5;
    s1.display();
    int t = s2;
    cout<<"t = "<<t<<endl;
}

