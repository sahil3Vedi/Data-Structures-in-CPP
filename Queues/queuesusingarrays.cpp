#include <iostream>

using namespace std;

class Queue{
  int* loc;//loc is not an array, but the pointer referencing an array
  int size;// max size of the queue
  int rear;// index of last element of the queue

  public:
    Queue(int s){
        size = s;
        loc = new int[s];//array that loc references is declared
        rear = 0;//if rear == 0 that means the queue is empty
    }

    //add element to the rear of the queue
    bool Enqueue(int x){
        if(rear==size){
            cout<<"Queue is full"<<endl;
            return false;
        } else{
            loc[rear++]=x;
            cout<<x<<" enqueued"<<endl;
            return true;
        }
    }

    int Dequeue(){
        if (rear==0){
            cout<<"Queue is Empty"<<endl;
            return 0;
        } else if (rear==1){
            cout<<loc[rear]<<" dequeued"<<endl;
            return loc[rear--];
        } else {
            int firstElem = loc[0];
            for(int i=1;i<rear;i++){
                loc[i-1]=loc[i];
            }
            rear--;
            cout<<firstElem<<" dequeued"<<endl;
            return firstElem;
        }
    }
};

int main()
{
    Queue* Q = new Queue(5);
    Q->Enqueue(1);
    Q->Enqueue(2);
    Q->Enqueue(3);
    Q->Enqueue(4);
    Q->Enqueue(5);
    Q->Enqueue(6);
    Q->Dequeue();
    Q->Dequeue();
    Q->Dequeue();
    Q->Dequeue();
    Q->Dequeue();
    Q->Dequeue();
}
