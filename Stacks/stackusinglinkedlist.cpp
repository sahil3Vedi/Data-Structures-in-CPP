#include <iostream>

using namespace std;

class Node{
  public:
    int val;
    Node *next;
    Node *prev;
    Node(int v){
        val = v;
        prev = NULL;
        next = NULL;
    }
};

class Stack{
  Node* head;
  public:
    Stack(){
        head = NULL;
    }
    bool isEmpty(){
        if(head==NULL){
            return true;
        } else {
            return false;
        }
    }
    void Push(int N){
        Node* P = new Node(N);
        if(head==NULL){
            cout<<"head is NULL"<<endl;
            head = P;
        } else if(head->next==NULL){
            cout<<"head->next is NULL"<<endl;
            head->next = P;
        } else {
            //traverse to end of the linked list
            Node* temp = head;
            while(temp->next!=NULL){
                cout<<"Travelling through"<<temp->val<<endl;
                temp=temp->next;
            }
            temp->next = P;
        }
    }
    int Pop(){
        if (head==NULL){
            cout<<"Stack is empty"<<endl;
            return 0;
        } else if(head->next==NULL){
            cout<<"head->next is NULL"<<endl;
            head=NULL;
        } else {
            // traverse to the second last element of the linked list
            Node* temp = head;
            Node* pretemp = NULL;
            while(temp->next!=NULL){
                cout<<"Travelling through"<<temp->val<<endl;
                pretemp = temp;
                temp = temp->next;
            }
            pretemp->next = NULL;
            return temp->val;
        }
    }
    int Peek(){
        if (head==NULL){
            cout<<"Stack is empty"<<endl;
            return 0;
        } else {
            // traverse to the last element of the linked list
            Node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            return temp->val;
        }
    }
};

int main()
{
    Stack s;
    s.Push(10);
    cout<<s.Peek()<<endl;
    s.Push(20);
    cout<<s.Peek()<<endl;
    s.Push(30);
    cout<<s.Peek()<<endl;
    s.Push(40);
    cout<<s.Peek()<<endl;
    s.Push(50);
    cout<<s.Peek()<<endl;
    s.Pop();
    cout<<s.Peek()<<endl;
    s.Pop();
    cout<<s.Peek()<<endl;
    s.Pop();
    cout<<s.Peek()<<endl;
    s.Pop();
    cout<<s.Peek()<<endl;
    s.Pop();
    cout<<s.Peek()<<endl;
}
