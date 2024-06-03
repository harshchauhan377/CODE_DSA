#include<iostream>
using namespace std ;

class Node{
    public:
    int data ;
    Node *left , *right ;

    Node (int value){
        data = value;
        left = right = NULL;
    }
};


void preorder(Node * root){
    if(root==NULL){
        return ;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node * root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

void postorder(Node * root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}

Node *Binarytree(){
    int x ;
    
    cin>>x;

    if(x == -1){
        return NULL;
    }

    Node * temp = new Node(x);
    cout<<"ENter Root Value left "<<x <<": ";
    temp->left=Binarytree();
    cout<<"ENter Root Value right "<<x <<": ";
    temp->right=Binarytree();
    return temp ;
}

int main(){
    cout<<"ENter Root Value  : ";
    Node * root = Binarytree();

    cout<<"preorder : ";
    preorder(root);
    cout<<" ";

    cout<<"inorder : ";
    inorder(root);
    cout<<" ";

    cout<<"postorder : ";
    postorder(root);
    cout<<" ";
    return 0;
}