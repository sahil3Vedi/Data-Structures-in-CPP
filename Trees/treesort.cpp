#include <iostream>

using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int V){
        val = V;
        left = NULL;
        right = NULL;
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
};

class Tree{
    public:
        TreeNode* rootNode;

    Tree(int A[], int size){
        rootNode = new TreeNode(A[0]);
        for (int i=1;i<size;i++) {
            addNode(A[i],rootNode);
        }
    }

    void addNode(int V,TreeNode* TNode){
        TreeNode* TN = new TreeNode(V);
        if (V<TNode->val){
            if (TNode->left==NULL){
                TNode->left = TN;
            } else {
                addNode(V,TNode->left);
            }
        } else {
            if (TNode->right==NULL){
                TNode->right = TN;
            } else {
                addNode(V,TNode->right);
            }
        }
    }

    void PrintTree(){
        rootNode->PrintNode();
    }
};

int main()
{
    int A[7] = {40,50,30,20,70,10,60};
    int size = *(&A + 1) - A;
    Tree* T = new Tree(A,size);
    T->PrintTree();
}
