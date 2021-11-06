#include<iostream>
using namespace std;
class Table{
private:
    int **t;
    int temp;
    int rows;
    int columns;
public:
    Table():rows(0),columns(0){
        t = new int *[rows];
        for(int i=0;i<rows;i++){
            t[i] = new int[columns];
            for(int j=0;j<columns;j++){
                t[i][j] = 0;
            }
        }
    }
    Table(int x,int y):rows(x),columns(y){
        t = new int *[rows];
        for(int i=0;i<rows;i++){
            t[i] = new int[columns];
            for(int j=0;j<columns;j++){
                t[i][j] = 0;
            }
        }
    }
    ~Table(){
        for(int i=0;i<rows;i++){
            delete []t[i];
        }
        delete []t;
    }
    int* &operator[](int i){
        return t[i];
    }
    friend istream & operator >>(istream &,Table &);
    friend ostream & operator <<(ostream &,Table &);
};
istream &operator>>(istream &din,Table &T){
    int r = T.rows,c = T.columns;
    cout<<"Enter the values inside the 4x5 matrix:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            din>>T.t[i][j];
        }
    }
    return din;
}
ostream &operator << (ostream &dout,Table &T){
    int r = T.rows,c = T.columns;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            dout<<T.t[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dout;
}
int main(){
    Table t(4, 5), t1(4, 5);
    cin >> t;
    t[0][0] = 5;
    int x = t[2][3];
    t1 = t;
    cout<<x<<endl;
    cout <<"Value of matrix t is:\n"<< t << "\n" <<"Value of matrix t1 is:\n"<<t1;
    return 0;
}
