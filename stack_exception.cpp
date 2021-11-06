#include<iostream>
using namespace std;
const int MAX = 3;
template <class Type>
class Stack{
private:
    int top;
    Type stack_arr[MAX];
public:
    class Range{};
    Stack();
    void push(Type value);
    Type pop();
};
template<class Type>
Stack<Type>::Stack(){top = -1;}
template<class Type>
void Stack<Type>::push(Type value){
    if(top>=MAX-1)
        throw Range();
    stack_arr[++top] = value;
}
template<class Type>
Type Stack<Type>::pop(){
    if(top<0)
        throw Range();
    return stack_arr[top--];
}
int main(void){
    Stack<int> s1;
    try{
        s1.push(11);
        s1.push(22);
        s1.push(33);
        s1.push(44);
        cout<<"Popped element is: "<<s1.pop()<<endl;
        cout<<"Popped element is: "<<s1.pop()<<endl;
        cout<<"Popped element is: "<<s1.pop()<<endl;
        cout<<"Popped element is: "<<s1.pop()<<endl;
    }
    catch(Stack<int>::Range){
        cout<<"Exception: Stack either empty or full"<<endl;
    }
    cout<<"Arrived here after catch(or normal exit)"<<endl;
}
