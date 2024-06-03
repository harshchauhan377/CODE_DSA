#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node * next;

    Node(int val){
        data = val ;
        next = NULL;
    }
};
Node* Creatinglinklist(){
    int value ;
    Node* head = NULL;
    Node* curr = NULL;

    while(cin>>value && value != -1){
       if(head ==NULL){
        head =  new Node(value);
        curr = head ;
       }
       else{
        curr->next = new Node (value);
        curr = curr ->next;
       }
    }
    return head;

}
int getlen(Node* head){
    int length = 0 ;
    while(head != NULL){
        length++;
        head = head->next;
    }
    return length;
}

Node* kthlast(Node * head , int k ){
    int leng = getlen(head);

    if(k>leng || k<=0){
        return NULL;

    }
    Node* cur = head;
    for(int i =0 ; i<leng - k;i++){
        cur = cur -> next;
    }

    return cur;
}

int main(){
    Node * head = Creatinglinklist();

    int k ;
    cout<<"kth ele from last : ";
    cin>>k ;

    Node *kthNode = kthlast(head , k);

    if (kthNode != NULL) {
        cout << "The " << k << "th element from the end is: " << kthNode->data << endl;
    } else {
        cout << "The linked list is shorter than " << k << " elements or k is non-positive." << endl;
    }

    return 0 ;
}