#include<iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;

        //constructor
        Node(int data){
            this->data = data;
            next = NULL;
        }

        //destructor
        ~Node(){
            int value = this->data;
            cout<<"you called me.."<< value;
        }
};

void insertAtHead(Node* &head, int d ){
    Node* temp;
    temp = new Node(d);
    temp-> next = head;
    // cout<<temp->next<<endl;
    head = temp;

}  

void InsertAtTail(Node* &tail, int d){
    Node* temp;
    temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void InsertAtPosition(Node* &head, Node* &tail ,int position, int d){

    if(position ==1 ){
        insertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int count = 1;

    while(count< position -1){
        temp = temp->next;
        count++;
    }
    // last node insertion
    if(temp->next == NULL){
        InsertAtTail(tail,d);
        return;
    }


    Node* newnode;
    newnode = new Node(d);
    newnode-> next = temp->next;
    temp->next = newnode;

    

}

//deletion


void deleteHead(Node* &head ){
    Node* temp = head;
    head = temp->next;
    temp->next = NULL;

}

void deletePosition(Node* &head, int pos){
    Node* temp = head;
    int cnt =1;

    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }
    Node* del = temp->next;
    // delete del;
    // del-> next = NULL; // if we null the del node first then the list  temp will be null;
    temp->next= temp->next->next;
    del->next = NULL;
    delete del;


}

void print(Node* &head){
    Node* temp; 

    temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp->next;
    }
    cout<<endl; 
}


int main(){
    Node node1(10);
    // Node node1;
    // node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;


    Node* head= &node1;
    Node* tail = &node1;
    print(head);
    insertAtHead(head,1);
    insertAtHead(head,2);
    InsertAtTail(tail,11);
    InsertAtTail(tail,12);
    // InsertAtPosition(head,tail,6,9);
    print(head);
    // deleteHead(head);
    deletePosition(head,3);     
    print(head);


    return 0;

}