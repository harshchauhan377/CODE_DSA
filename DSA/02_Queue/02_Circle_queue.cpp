#include<iostream>
using namespace std ;

//Implement queue using Circle Queue
class Queue{
    int *arr;
    int front , rear , size;

    public:
    //constructor
    Queue(int n){
        arr = new int[n];
        size = n ;
        front = rear = -1;
    }

    //if queue is empty or not 
    bool isEmpty(){
        return front == -1;
    }
    //queue is full
    bool isFull(){
        return (rear + 1)%size == front;
    }
    //push element in queue
    void push(int x ){
        if(isEmpty()){
            cout<<"pushed "<<x<<" into rhe Queue\n";
            front = rear = 0;
            arr[0]=x;
        }
        else if(isFull()){
            cout<<"Queue overflow\n";
            return;
        }
        else{
            rear = (rear + 1) % size;
            arr[rear]= x;
            cout<<"pushed "<<x<<" into the queue\n";
        }
    }
    //pop element
    void pop(){
        if(isEmpty()){
            cout<<"queue underflow \n";
            return;
        }
        else{
            if(front == rear ){
                cout<<"popped "<<arr[front]<<" into the queue";
                front = rear = -1 ;

            }
            else{
                cout << "popped " << arr[front] << " from the Queue\n";
                front=(front+1)%size;

            }
        }
    }
    //starting element
    int start(){
        if (isEmpty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        else{
            return arr[front];
        }


    }
};

int main() {
    Queue a(5);
    a.push(5);
    a.push(15);
    a.push(34);
    a.push(45);
    a.push(44);
    a.pop();
    a.pop();
    a.pop();
    int x = a.start();
    if (!a.isEmpty())
        cout << "Starting element: " << x << "\n";
    a.push(15);
    a.push(34);

    return 0;
}