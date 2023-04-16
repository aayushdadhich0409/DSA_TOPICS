#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void InsertatHead(Node* &head, int d){
    Node* temp = head;
    Node* newNode = new Node(d);
    temp->prev = newNode;
    newNode->next = temp;
    head = newNode; 
}
void insertAtTail(Node* &tail,int d){
    Node* temp= tail;
    Node* NewNode = new Node(d);
    tail->next = NewNode; 
    NewNode->prev = tail;
    tail = NewNode;

}

void InsertAtPosition(Node* &head, int d, int pos,Node* &tail){
    Node* temp; 
    temp = head;
    int cnt=1;

    while(cnt< pos){
        temp = temp->next;
        cnt++;
    }
    if(temp == head){
        InsertatHead(head,d);
        return;
    }
    if(temp == tail){
        insertAtTail(tail,d);
        return;
    }
    else{
        Node* newNode = new Node(d);
        newNode ->next = temp;
        newNode ->prev = temp -> prev;
        temp -> prev -> next = newNode;
        temp -> prev = newNode;
    }
    
}

void deleteNode(Node* &head){
     Node* temp = head; 
     if(temp == head){
         head->next->prev = NULL;
         head = temp ->next;
         temp->next = NULL;


     }
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp->next;

    }
    cout<<endl;
}
int main(){

    Node* Node1 = new Node(10);
    Node* head = Node1;
    Node* tail = Node1;
    InsertatHead(head,4);
    insertAtTail(tail,5);
    insertAtTail(tail,6);
    insertAtTail(tail,8);
    print(head);
    InsertAtPosition(head,0,3,tail);
    print(head);
    deleteNode(head);
    print(head);
    return 0;
}