#include <iostream>

using namespace std;

int getLeftArraySize(int s) {
    int l = 0;
    int increment = 1;
    int r = 0;
    bool addLeft = true;
    while(l+r<s){
        if(addLeft){
            l+=increment;
            addLeft = false;
            if (l+r>s){
                int diff = l+r-s;
                l-=diff;
            }
        } else {
            r+=increment;
            increment *= 2;
            addLeft = true;
            if (l+r>s){
                int diff = l+r-s;
                r-=diff;
            }
        }
    }
    return l;
}

int getRightArraySize(int s) {
    int l = 0;
    int increment = 1;
    int r = 0;
    bool addLeft = true;
    while(l+r<s){
        if(addLeft){
            l+=increment;
            addLeft = false;
            if (l+r>s){
                int diff = l+r-s;
                l-=diff;
            }
        } else {
            r+=increment;
            increment *= 2;
            addLeft = true;
            if (l+r>s){
                int diff = l+r-s;
                r-=diff;
            }
        }
    }
    return r;
}

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int A[], int s){
            // Size can either be 1 or more
            if (s==1){
                val = A[0];
                left = NULL;
                right = NULL;
            } else if (s==2){
                int leftArray[1] = {A[1]};
                TreeNode* LTN = new TreeNode(leftArray,1);
                val = A[0];
                left = LTN;
                right = NULL;
            }else {
                // forming Left and Right Arrays
                int LS = getLeftArraySize(s-1);
                int RS = getRightArraySize(s-1);
                int leftArray[LS];
                int rightArray[RS];
                int leftAdded = 0;
                int rightAdded = 0;
                int increment = 1;
                int adds_remaining = increment;
                bool addLeft = true;
                for(int x=1;x<s;x++){
                    if (addLeft){
                        leftArray[leftAdded]=A[x];
                        leftAdded+=1;
                        adds_remaining--;
                        if(adds_remaining==0){
                            addLeft=false;
                            adds_remaining=increment;
                        }
                    } else {
                        rightArray[rightAdded]=A[x];
                        rightAdded+=1;
                        adds_remaining--;
                        if(adds_remaining==0){
                            addLeft=true;
                            increment*=2;
                            adds_remaining=increment;
                        }
                    }
                }
                TreeNode* LTN = new TreeNode(leftArray,LS);
                TreeNode* RTN = new TreeNode(rightArray,RS);
                val = A[0];
                left = LTN;
                right = RTN;
            }
        }

        void PrintNode(){
            if(left!=NULL){
                left->PrintNode();
            }
            cout<<val<<" ";
            if(right!=NULL){
                right->PrintNode();
            }
        }

        void InvertNode(){
            if ((left!=NULL)&&(right!=NULL)){
                left->InvertNode();
                right->InvertNode();
                TreeNode* temp = left;
                left = right;
                right = temp;
            } else if ((left!=NULL)&&(right==NULL)){
                left->InvertNode();
                right = left;
                left = NULL;
            } else if ((right!=NULL)&&(left==NULL)){
                right->InvertNode();
                left = right;
                right = NULL;
            }
        }
};

class Tree{
    public:
        TreeNode* rootNode;

    Tree(int A[], int s){
        //recursively form child and parent nodes
        TreeNode* root = new TreeNode(A, s);
        rootNode = root;
    }

    void PrintTree(){
        if (rootNode==NULL){
            cout<<"Root Node is Null"<<endl;
        } else {
            rootNode->PrintNode();
        }
    }

    void InvertTree(){
        if (rootNode==NULL){
            cout<<"Tree is Empty"<<endl;
        } else {
            rootNode->InvertNode();
        }
    }

};

int main()
{
    int A[5] = {10,20,30,40,50};
    int size = *(&A + 1) - A;
    Tree* T = new Tree(A, size);
    T->PrintTree();
    T->InvertTree();
    cout<<endl;
    T->PrintTree();
}
