#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node{
    public:
    int data;
    Node * left , *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }

};

Node * BST(vector<int>&inorder , int start , int end){
    if(start>end) return NULL;

    int mid = start + (end - start) / 2;
    Node * root = new Node (inorder[mid]);
    root->left = BST(inorder , start , mid -1);
    root->right = BST(inorder , mid + 1 , end);
    return root;
}

Node *post_bst(int postorder[] , int size){

    vector<int>inorder(postorder,postorder + size);

    sort(inorder.begin(),inorder.end());
    return BST(inorder,0,inorder.size()-1);
}

void inorderT(Node * root){
    if(!root) return;
    inorderT(root->left);
    cout<<root->data<<" ";
    inorderT(root->right);
}

int main(){
int postorder[]={1,7,5,50,40,10};
int size = sizeof(postorder)/sizeof(postorder[0]);
Node * root = post_bst(postorder,size);

cout << "Inorder Traversal of the constructed BST: ";
    inorderT(root);
    cout << endl;

    return 0;
}
