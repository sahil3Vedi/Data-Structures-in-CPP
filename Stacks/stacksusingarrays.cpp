#include <iostream>

using namespace std;

class Stack{
  int* loc;//loc is not an array,but the pointer referencing an array
  int size;
  int top;

  public:
    Stack(int s){
        size = s;
        loc = new int[s];// array that loc references is declared
        top = -1;
    }

    bool Push(int x){
        if (top==size-1){
            cout<<"Stack is Full"<<endl;
            return false;
        } else {
            top+=1;
            loc[top]=x;
            cout<<x<<" added to Stack"<<" current Top of Stack: "<<top<<endl;
        }
    }

    int Pop(){
        if (top==-1){
            cout<<"Stack is empty"<<endl;
            return 0;
        } else {
            int topElem  = loc[top--];
            cout<<topElem<<" is on the top of the stack."<<" current Top of Stack: "<<top<<endl;
            return topElem;
        }
    }

    int Peek(){
        if (top==-1){
            cout<<"Stack is empty"<<endl;
            return 0;
        } else {
            int topElem  = loc[top];
            cout<<topElem<<" is on the top of the stack"<<endl;
            return topElem;
        }
    }

    bool isEmpty(){
        if (top==-1){
            cout<<"Stack is empty"<<endl;
            return true;
        } else {
            cout<<"Stack is not empty"<<endl;
            return false;
        }
    }

};

int main()
{
    Stack* st = new Stack(5);
    st->Push(1);
    st->Push(2);
    st->Push(3);
    st->Push(4);
    st->Push(5);
    st->Push(6);
    st->Peek();
    st->isEmpty();
    st->Pop();
    st->Pop();
    st->Pop();
    st->Pop();
    st->Pop();
    st->Pop();
    st->Peek();
    st->isEmpty();
}
