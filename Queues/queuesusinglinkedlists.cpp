#include <iostream>

using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int v){
            val = v;
            next = NULL;
        }
};

class Queue{
  Node* front;//pointer to the front Node of the Queue

  public:
    Queue(){
        front = NULL;
    }

    //add element to the rear of the queue
    void Enqueue(int x){
        Node* N  = new Node(x);
        //if queue is empty
        if (front == NULL){
            front = N;
        }
        // if queue has one element
        else if (front->next == NULL) {
            front->next = N;
        }
        // if queue has more than one element
        else {
            Node* temp = front;
            while(temp->next != NULL) {
                temp=temp->next;
            }
            temp->next = N;
        }
        cout<<x<<" enqueued"<<endl;
    }

    // remove element from the front of the queue
    int Dequeue(){
        //if queue is empty
        if (front == NULL){
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        // if queue has more than one element
        else {
            int ret = front-> val;
            front = front->next;
            cout<<ret<<" dequeued"<<endl;
            return ret;
        }
    }
};

int main()
{
    Queue Q;
    int N = 5;
    for (int i=0;i<N;i++){
        Q.Enqueue(i+1);
    }
    for (int i=-1;i<N;i++){
        Q.Dequeue();
    }
}
