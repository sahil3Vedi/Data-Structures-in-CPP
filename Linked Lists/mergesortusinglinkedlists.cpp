#include <iostream>

using namespace std;

class Node{
    public:
        int val;
        Node* next;

    Node(int V){
        val = V;
        next = NULL;
    }
};

class LinkedList{
    public:
        Node* front;
        int size;

        LinkedList(int A[],int s){
            size = s;
            if (size>0){
                front = new Node(A[0]);
            }
            else{
                front = NULL;
            }
            for (int i=1; i<s ; i++){
                addNode(A[i],front);
            }
        }

        void addNode(int V,Node* N){
            Node* ND = new Node(V);
            if (N->next==NULL){
                N->next=ND;
            } else {
                addNode(V,N->next);
            }
        }

        void PrintList(){
            Node* temp = front;
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }

        void checkSwap(){
            //called only when there are two elements in the Linked List;
            if (front->val>front->next->val){
                front->next->next=front;
                front=front->next;
                front->next->next=NULL;
                cout<<front->next->val<<" "<<front->val<<"swapped"<<endl;
            }
        }

        void quickSort(){
            // divide the list along the Pivot value (front pivot)
            ////find the number of elements > and < and = the pivot
            int gtp = 0;
            int ltp = 0;
            int ep = 0;
            Node* temp = front;
            while(temp!=NULL){
                if (temp->val>front->val){
                    gtp+=1;
                }
                else if (temp->val<front->val){
                    ltp+=1;
                }
                else {
                    ep+=1;
                }
                temp=temp->next;
            }
            ////form subArrays with those elements and then subLinkedLists with those subArrays
            int sub1[gtp];
            int sub2[ltp];
            int sub3[ep];
            Node* temp1 = front;
            int gcap = 0;
            int lcap = 0;
            int ecap = 0;
            while(temp1!=NULL){
                if (temp1->val>front->val){
                    sub1[gcap]=temp1->val;
                    gcap+=1;
                }
                else if (temp1->val<front->val) {
                    sub2[lcap]=temp1->val;
                    lcap+=1;
                } else {
                    sub3[ecap]=temp1->val;
                    ecap+=1;
                }
                temp1=temp1->next;
            }
            LinkedList* L1 = new LinkedList(sub1,gtp);// Greater List
            LinkedList* L2 = new LinkedList(sub2,ltp);// Lesser List
            LinkedList* L3 = new LinkedList(sub3,ep);// Equal List


            // quickSort the divided lists
            ////Sorting L1
            if (gtp==0){
                L1->front = NULL;
            } else if (gtp==1) {
            } else if (gtp==2) {
                L1->checkSwap();
            } else {
                L1->quickSort();
            }
            ////Sorting L2
            if (ltp==0){
                L2->front = NULL;
            } else if (ltp==1) {
            } else if (ltp==2) {
                L2->checkSwap();
            } else {
                L2->quickSort();
            }

            // join the linked lists L2 and L3 and L1
            ////join L1 and L3
            front=L3->front;
            Node* jtemp = front;
            while(jtemp->next!=NULL){
                jtemp=jtemp->next;
            }
            jtemp->next = L1->front;
            if (ltp==0){
            } else{
                front = L2->front;
                Node* ktemp = front;
                while (ktemp->next!=NULL){
                    ktemp=ktemp->next;
                }
                ktemp->next = L3->front;
            }
        }

};

int main()
{
    int A[10] = {70,40,50,30,20,10,60,5,1,9};
    int size = *(&A + 1) - A;
    LinkedList* L = new LinkedList(A,size);
    L->PrintList();
    L->quickSort();
    L->PrintList();
}
