/* 
______________________________________________________________________________
Insertion --Start
          --End
          --Middle
_______________________________________________________________________________


Class Node{
    public :
    int data;
    Node * next
    Node(int Value){
        data = value ;
        next = null;
    }
}
int main (){
    Node * Head ;
    Head = new Node(4);
}


      4 | Null
    Data   next(address of another no.)
       Node
*/ 


/*
_________________________

START
__________________________
*/


#include<iostream>
using namespace std ;

class Node
{
    public:
    int data;
    Node *next;

    Node(int value){
        data = value ;
        next = NULL;
    }


};

int main(){
    // Node A1(4);
    Node *Head , *Tail;
    Tail = Head = NULL;
    // Head = new Node(4);
    // cout<<Head->data<<endl;
    // cout<<Head->next<<endl;

    int arr[] = {2,4,6,8,10};
    //Inser the node at beginning

    //Linklist Doesn't exixt

    for(int i=0;i<5;i++)
    {
        if(Head==NULL){
            Head =new Node(arr[i]);
            Tail = Head ;
        }
        else{
           Tail->next = new Node(arr[i]);
           Tail = Tail ->next;
        }

    }

    //Print the Values;

    Node *temp = Head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp =temp->next;
    };
    

    

}





