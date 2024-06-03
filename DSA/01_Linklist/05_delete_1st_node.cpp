#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = NULL;
    }

};

Node* CreateLinkList(int arr[] , int index , int size){

    //Base Case
    if(index==size){
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[index]);
    temp->next = CreateLinkList(arr,index+1,size);

    return temp;
}
    
int main(){
    Node *Head;
    Head = NULL;

    int arr[]={2,4,6,8,10};

    Head = CreateLinkList(arr,0,5);

    if(Head!=NULL){
        Node *temp = Head;
        Head = Head ->next;
        delete temp;
    }

    //print the Value
    Node *temp;
    temp = Head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    

}