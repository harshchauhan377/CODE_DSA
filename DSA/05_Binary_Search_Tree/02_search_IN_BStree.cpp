#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left , *right ;

    Node (int value){
        data = value;
        left = right = NULL;
    }
};

Node * insert(Node * root , int target){
    if(!root){
        return new Node (target);
    }
    if(target < root->data){
        root->left = insert(root->left,target);
    }
    else{
        root->right= insert(root->right,target);
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

bool search(Node * root , int ele){
    if(!root){
        return 0;
    }

    if(root->data == ele){
        return 1;
    }

    if(root->data>ele){
        return search(root->left,ele);
    }
    else{
        return search(root->right,ele);
    }
}

int main(){
    int n ;
    cout<<" NO. of Element In Array : ";
    cin>>n;
    int arr[n];
    cout<<" Array Element : ";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    //insering array ele into bineary search tree
    Node * root = NULL;
    for(int i =0;i<n;i++){
        root=insert(root,arr[i]);
    }

    //printing element in inorder or in assending order
    inorder(root);

    
    //searching ele in bineary search tree
    int search_ele;
    cout<<"Which Element You want To Seach In Bineary Search Tree : ";
    cin>>search_ele;
  
    cout<<search(root,search_ele)<<" ";


    return 0;

}