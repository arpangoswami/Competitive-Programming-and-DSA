#include<iostream>
#include<fstream>
using namespace std;
int main(void){
    ifstream infile("My.txt");
    //ofstream outfile("My.txt",ios::app);
    char c;
    while(!infile.eof()){
        c = infile.get();
        if(c == 65 || c == 69 || c == 73 || c == 79 || c == 85 || c == 97 || c == 101 || c == 105 || c == 111 || c == 117){
            cout<<c<<endl;
        }
        //c++;
        //outfile.put(c);
    }
    infile.close();
}
