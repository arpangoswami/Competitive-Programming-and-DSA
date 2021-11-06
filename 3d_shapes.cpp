#include<iostream>
#include<vector>
#define PI 3.14159
using namespace std;
class Shape{
public:
    virtual void name() = 0;
    virtual void area() = 0;
    virtual void volume() = 0;
};

class TwoDshape: public Shape{
string shape;
public:
    TwoDshape():shape("NA"){}
    TwoDshape(string str):shape(str){}
    void name(){
        if(shape!="NA")
            cout<<"It's a "<<shape<<endl;
        else
            cout<<"No value entered"<<endl;
    }
    void area(){}
    void volume(){cout<<"Sorry it's a 2D shape it doesn't have volume\n";}
};
class ThreeDshape: public Shape{
    string shape;
public:
    ThreeDshape():shape("NA"){}
    ThreeDshape(string str):shape(str){}
    void name(){
        if(shape!="NA")
            cout<<"It's a "<<shape<<endl;
        else
            cout<<"No value entered"<<endl;
    }
    void area(){}
    void volume(){}
};
class Circle:public TwoDshape{
private:
        double radius;
public:
    Circle():TwoDshape("Circle"),radius(0){}
    Circle(double r):TwoDshape("Circle"),radius(r){}
    void name(){
        TwoDshape::name();
    }
    void area(){
        cout<<"Area of the circle is "<<PI*radius*radius<<endl;
    }
    void volume(){
        TwoDshape::volume();
    }
};
class Triangle:public TwoDshape{
private:
        double height;
        double base;
public:
    Triangle():TwoDshape("Triangle"),height(0),base(0){}
    Triangle(double b,double h):TwoDshape("Triangle"),height(h),base(b){}
    void name(){
        TwoDshape::name();
    }
    void area(){
        cout<<"Area of the triangle is "<<0.5*base*height<<endl;
    }
    void volume(){
        TwoDshape::volume();
    }
};
class Ellipse:public TwoDshape{
private:
        double semiminor;
        double semimajor;
public:
    Ellipse():TwoDshape("Ellipse"),semiminor(0),semimajor(0){}
    Ellipse(double smaj,double smin):TwoDshape("Ellipse"),semimajor(smaj),semiminor(smin){}
    void name(){
        TwoDshape::name();
    }
    void area(){
        cout<<"Area of the ellipse is "<<PI*semimajor*semiminor<<endl;
    }
    void volume(){
        TwoDshape::volume();
    }
};
class Sphere:public ThreeDshape{
private:
    double radius;
public:
    Sphere():ThreeDshape("Sphere"),radius(0){}
    Sphere(double r):ThreeDshape("Sphere"),radius(r){}
    void name(){
        ThreeDshape::name();
    }
    void area(){
        cout<<"Surface area of the sphere is: "<<4*PI*radius*radius<<endl;
    }
    void volume(){
        cout<<"Volume of the ellipse is: "<<1.33F*PI*radius*radius*radius<<endl;
    }
};
class Cube:public ThreeDshape{
private:
    double edge;
public:
    Cube():ThreeDshape("Cube"),edge(0.0){}
    Cube(double e):ThreeDshape("Cube"),edge(e){}
    void name(){
        ThreeDshape::name();
    }
    void area(){
        cout<<"Surface area of the cube is: "<<6*edge*edge<<endl;
    }
    void volume(){
        cout<<"Volume of the cube is: "<<edge*edge*edge<<endl;
    }
};
int main(void){
    vector<Shape*>container(5);
    container[0] = new Circle(5);
    container[1] = new Triangle(3,4);
    container[2] = new Ellipse(4,5);
    container[3] = new Sphere(4);
    container[4] = new Cube(5);
    for(int i=0;i<5;i++){
        container[i]->name();
        container[i]->area();
        container[i]->volume();
    }
}
