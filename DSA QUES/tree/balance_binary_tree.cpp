#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<sstream>
using namespace std;

class Node{
    public:
    int data;
    Node *left , *right ;

    Node (int val){
        int data = val;
        left = right = NULL;
    }
};

Node *binarytree(istringstream &iss){
    int x ;
    if(!(iss>>x) || x == -1){
        return NULL;
    }

    Node *temp = new Node(x);
    temp->left=binarytree(iss);
    temp->right=binarytree(iss);
    return temp;
}

int height(Node *binarytree , bool& valid){
    if(binarytree == NULL){
        return 0;
    }

    int l = height(binarytree->left , valid);
    int r = height(binarytree->right , valid);
    if(abs( l - r )>1){
        return false;
    }

    return max(l , r )+1;
}

bool isbinary(Node *binarytree){
    bool valid = true;
    height(binarytree , valid);
    return valid;

}

int main(){
    string input;
    getline(cin,input);
    istringstream iss(input);

    Node *head = binarytree(iss);
    if (!isbinary(head)) {
        cout << "false" << endl;
    }

    return 0;
}