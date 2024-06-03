#include<iostream>
#include<queue>
using namespace std;

int main(){
    // max heap 
    priority_queue<int> pq;
    pq.push(4);
    pq.push(24);
    pq.push(14);
    pq.push(43);
    pq.push(44);
    pq.push(1);

    cout<<"element on top : "<<pq.top()<<endl;
    pq.pop();
    cout<<"element on top : "<<pq.top()<<endl;
       

    // min heap 
    priority_queue<int , vector<int> ,greater<int> > min;
    min.push(4);
    min.push(24);
    
    min.push(1);

    cout<<"element on top : "<<min.top()<<endl;
    min.pop();
    cout<<"element on top : "<<min.top()<<endl;
    cout<<min.size();
    
    return 0;
}