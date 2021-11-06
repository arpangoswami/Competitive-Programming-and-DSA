#include<iostream>
class Distances{
protected:
    int feet;
    float inches;
public:
    Distances():feet(0),inches(0.0){}
    Distances(int ft,float in):feet(ft),inches(in){}
    void getdata(){
        cout<<"Enter values for feet and inches respectively:\n"<<endl;
        cin>>feet>>inches;
    }
    void showdata(){
        cout<<feet<<"\'"<<inches<<"\""<<endl;
    }
};
class Distances_sign : public Distances{
private:
    char ch;
public:
    Distances_sign():Distances(){ch = '+';}
    Distances_sign(int ft,float in,char sign='+'):Distances(ft,in),ch(sign){}
    void getdata(){
        Distances::getdata();

    }
};
