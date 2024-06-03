#include<iostream>
using namespace std;

class Node{
    public:
    int data ;
    Node *left , *right ;

    Node (int value){
        data = value;
        left = right = NULL;
    }


};


Node *insert(Node *root, int target){
    //base case
    if(!root){
        return new Node (target);
    }

    if(target<root->data){
        root->left = insert(root->left,target);
    }
    else{
        root->right = insert(root->right,target);
    }
    return root;
}

void inorder(Node * root){
    if(!root)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    int n ;
    cout<<"Array Size : ";
    cin>>n;
    cout<<"Insert Array Element : ";
    int arr[n];
    for(int i =0 ;i<n;i++){
        cin>>arr[i];
    }

    Node *root = NULL;

    for(int i = 0 ; i<n ;i++){
        root = insert(root,arr[i]);
    }
    inorder(root);
    return 0;

}
