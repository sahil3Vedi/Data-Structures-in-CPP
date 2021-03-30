// Hash Tables with operations: Insert, Search & Remove

#include <iostream>

using namespace std;

int HashIndex(string k){
    char F = k[0];
    int f;
    f = int(F);
    return f%26;
}

class Obj{
    public:
        string key;
        string value;

        Obj(string k, string v){
            key = k;
            value = v;
        }

        void printObject(){
            cout<<"{"<<key<<":"<<value<<"}"<<endl;
        }
};

class Node{
    public:
        Node* next;
        Obj* obj;

        Node(Obj* o){
            obj = o;
            next = NULL;
        }
};

class LinkedList{
    public:
        Node* rootNode;

        LinkedList(){
            cout<<"Initialiased Linked List"<<endl;
            rootNode = NULL;
        }

        void addObj(Obj* o){
            Node* N = new Node(o);
            if (rootNode==NULL){
                cout<<"List is NULL"<<endl;
                rootNode = N;
            } else {
                cout<<"List is not NULL"<<endl;
                Node* temp = rootNode;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=N;
            }
            cout<<"Object Added to Table"<<endl;
        }

        bool removeObj(string k){
            if (rootNode==NULL) {
                cout<<"Key doesn't exist in Table"<<endl;
                return false;
            } else if (rootNode->obj->key==k){
                cout<<"Object Removed from Table"<<endl;
                rootNode = rootNode->next;
                return true;
            } else {
                Node* temp = rootNode;
                while(temp->next!=NULL){
                    if (temp->next->obj->key==k){
                        cout<<"Object Removed from Table"<<endl;
                        temp->next = temp->next->next;
                        return true;
                    }
                    temp=temp->next;
                }
                cout<<"Key doesn't exist in Table"<<endl;
                return false;
            }
        }

        bool searchObj(string k){
            if (rootNode==NULL){
                cout<<"Key doesn't exist in Table"<<endl;
                return false;
            } else{
                Node* temp = rootNode;
                while(temp!=NULL){
                    if(temp->obj->key==k){
                        temp->obj->printObject();
                        return true;
                    }
                    temp=temp->next;
                }
                cout<<"Key doesn't exist in Table"<<endl;
                return false;
            }
        }
};

class HashTable{
    public:
        LinkedList* A;

        HashTable(){
            A = new LinkedList[26];
        }

        void insertObject(Obj* o){
            int hash = HashIndex(o->key);
            cout<<"Inserting at Hash Index "<<hash<<endl;
            A[hash].addObj(o);
        }

        bool removeObject(string k){
            int hash = HashIndex(k);
            return A[hash].removeObj(k);
        }

        bool searchObject(string k){
            int hash = HashIndex(k);
            cout<<"Searching at Hash Index "<<hash<<endl;
            return A[hash].searchObj(k);
        }
};

int main()
{
    //Declaring Objects
    Obj* O1 = new Obj("Name","Sahil");
    Obj* O2 = new Obj("Role","Author");

    //Declaring HashTable
    HashTable H;
    H.insertObject(O1);
    H.insertObject(O2);
    H.searchObject("Name");
    H.searchObject("Role");
}
