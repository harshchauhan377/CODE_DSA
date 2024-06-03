#include<iostream>
using namespace std;

// Queue implement using linklist
class Node{
    public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next=NULL;
    }
};

class Queue{
    Node *front,*rear ;
    public:
    Queue(){
        front=rear=NULL;
    }
    bool isEmpty(){
        return front==NULL;
    }

    //push element
    void push(int x){
        if(isEmpty()){
            cout<<"pushed "<<x<<" into the queue\n";
            front=rear=new Node(x);
            return;
        }
        else{
            rear->next=new Node(x);
            if(rear->next==NULL){
                cout<<"Queue Overflow\n";
            }
            cout<<"pushed "<<x<<" into the queue\n";
            rear = rear ->next;

        }
    }

    //pop
    void pop(){
        if(isEmpty()){
            cout<<"queue underflow"<<"\n";
            return;
        }
        else{
            cout<<"poper "<<front->data<<" from the queue\n";
            Node *temp = front;
            front = front ->next;
            delete temp;
        }
    }
    int start(){
        if(isEmpty()){
            cout<<"queue is empty\n";
            return -1;
        }
        else
        return front->data;
    }
};

int main (){
    Queue q;
    q.push(5);
    q.push(23);
    q.push(55);
    q.push(56);
    q.pop();
    cout<<q.start()<<endl;

}