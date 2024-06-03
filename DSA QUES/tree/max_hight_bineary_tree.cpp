#include<iostream>
#include<queue>
#include<sstream>
using namespace std ;

class Node {
    public :
    int data ;
    Node * left , *right;

    Node(int val){
        int data = val ;
        left =right = NULL;
    }
};

Node * binarytree(istringstream &iss){
    int x;
    if( !(iss>>x)|| (x == -1)){
        return NULL;
    }

    Node * temp = new Node (x);
    temp->left = binarytree(iss);
    temp->right = binarytree(iss);
    return temp;
}

int maxH(Node * binearytree){
    if(binearytree == NULL){
        return -1;
    }
    int l = maxH(binearytree->left);
    int r = maxH(binearytree->right);
    return max(l,r)+1;
}

int main(){
    string input;
    getline(cin,input);
    istringstream iss(input);

    Node * head = binarytree(iss);

    cout<<maxH(head);
}

