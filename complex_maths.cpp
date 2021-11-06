#include<bits/stdc++.h>
using namespace std;
class Complex{
    float real;
    float img;
public:
    Complex(){}
    Complex(float x,float y){
        real=x;img=y;
    }
    friend Complex operator +(Complex,Complex);
    friend Complex operator -(Complex,Complex);
    friend Complex operator *(Complex,Complex);
    friend istream & operator >> (istream &in,Complex &c);
    friend ostream & operator << (ostream &out,Complex &c);
};
Complex operator +(Complex C1,Complex C2){
    return Complex((C1.real+C2.real),(C1.img+C2.img));
}
Complex operator -(Complex C1,Complex C2){
    return Complex((C1.img-C2.img),(C1.img-C2.img));
}
Complex operator *(Complex C1,Complex C2){
    return Complex((C1.real*C2.real-C1.img*C2.img),(C1.real*C2.img + C1.img*C2.real));
}


