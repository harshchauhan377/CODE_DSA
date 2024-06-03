#include<iostream>
#include<queue>
using namespace std ;

class Node{
    public :
    int data ;
    Node *left , *right;

    Node (int value){
        data = value ;
        left = right = NULL;
    }
    
};

int main(){
    int x ;
    cout<<"enter the root element "<<" ";
    cin>>x;
    int first , second ;
    queue<Node*>q;
    Node *root = new Node(x);
    q.push(root);

    //built the binary tree
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout<<"enter left child of "<<temp->data<<": ";
        cin>>first; //left node ki value 
        //left node 
        if(first!= -1){
            
            temp->left = new Node(first);
            q.push(temp->left);
        }
        //right node 
        cout<<"enter right child of "<<temp->data<<": ";
        cin>>second;
        if(second!=-1){
            temp->right = new Node(second);// Corrected to use "second" instead of "first"
            q.push(temp->right);
        }

     
    }
return 0;
}