#include<iostream>
#include<fstream>
using namespace std;
class Student{
private:
    string name,college;
    int roll;
public:
    Student():name("No name"),college("Not provided"),roll(0){};
    Student(string name_f,string college_f,int roll_f):name(name_f),college(college_f),roll(roll_f){};
    void display(){
        cout<<"Name: "<<name<<"\nCollege: "<<college<<"\nRoll No: "<<roll<<endl;
    }
    friend istream & operator >>(istream &ifs,Student &s);
    friend ostream & operator <<(ostream &ofs,Student &s);
};
istream & operator >>(istream &ifs,Student &s){
    ifs>>s.name>>s.college>>s.roll;
    return ifs;
}
ostream & operator <<(ostream &ofs,Student &s){
    ofs<<s.name<<"\n"<<s.college<<"\n"<<s.roll<<endl;
    return ofs;
}
int main(void){
    ofstream output("My.txt",ios::trunc);
    Student s("ArpanGoswami","JadavpurUniversity",49),s1,s2;
    output<<s;
    output<<"RishikVarma"<<endl;
    output<<"JU"<<endl;
    output<<50<<endl;
    output.close();
    ifstream input("My.txt");
    if(!input.is_open())
        cout<<"File doesn't exist\n";
    string str1,str2;
    int roll;
    input>>s1>>s2;
    cout<<s1<<s2;
    //s2.display();
    //cout<<s1.name<<s1.college<<s1.roll<<endl;
    //cout<<s2.name<<s2.college<<s2.roll<<endl;
    input.close();
}
