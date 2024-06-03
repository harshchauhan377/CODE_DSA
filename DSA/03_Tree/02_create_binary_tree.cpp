#include<iostream>
using namespace std ;

class Node {
    public :
    int data ;
    Node * left , * right ;

    Node (int value){
        data = value ;
        left = right = NULL;
    }
};

Node * Binarytree(){
    int x ;
    cin>>x;
    // Base case: If x is -1, return NULL indicating no child
    if(x == -1 ){
        return NULL;
    }

    Node * temp = new Node (x);
    cout <<"root left child of "<<x<< " : ";
    temp->left = Binarytree(); //left 
    cout <<"root right child of "<<x<< " : ";
    temp -> right = Binarytree(); //right 
    return temp ;
}

int main ()
{
    cout<<"Enter thr Root Value : ";
    Node * root ;
    root = Binarytree();
    return 0 ;
}
