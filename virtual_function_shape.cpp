#include<iostream>
#define PI 3.14159
using namespace std;
class Shape{
public:
    virtual void perimeter() = 0;
    virtual void area() = 0;
};
class Rectangle: public Shape{
    private:
        double length;
        double breadth;
    public:
        Rectangle():length(0.0),breadth(0.0){}
        Rectangle(double l,double b):length(l),breadth(b){}
        void perimeter(){
            cout<<"The perimeter of the given rectangle is: "<<2*(length+breadth)<<endl;
        }
        void area(){
            cout<<"The area of the given area is: "<<(length*breadth)<<endl;
        }
};
class Circle:public Shape{
private:
    double radius;
public:
    Circle():radius(0){}
    Circle(double r):radius(r){}
    void perimeter(){
        cout<<"The perimeter of the given circle is: "<<2*PI*radius<<endl;
    }
    void area(){
        cout<<"The area of the given circle is: "<<PI*radius*radius<<endl;
    }
};
int main(void){
    Shape *arperi[5];
    arperi[0] = new Circle(5);
    arperi[1] = new Circle(3);
    arperi[2] = new Circle(2);
    arperi[3] = new Rectangle(3,4);
    arperi[4] = new Rectangle(4,5);
    for(int i=0;i<5;i++){
        arperi[i]->perimeter();
        arperi[i]->area();
        cout<<endl;
    }
}
