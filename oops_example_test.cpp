#include<iostream>
using namespace std;
class Counter{
private:
    unsigned int counting;
public:
    Counter():counting(0){}
    unsigned int get_count(){return counting;}
    Counter operator++(){
    ++counting;
    Counter temp;
    temp.counting = counting;
    return temp;
    }
};
int main(void){
        Counter c1,c2;
        cout<<"\nc1 = "<<c1.get_count();
        cout<<"\nc2 = "<<c2.get_count();
        ++c1;
        c2 = ++c1;
        cout<<"\nc1 = "<<c1.get_count();
        cout<<"\nc2 = "<<c2.get_count();
}
