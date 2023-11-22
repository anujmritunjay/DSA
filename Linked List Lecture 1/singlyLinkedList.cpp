#include<iostream>
using namespace std;

class Node{
    public:
    Node* next;
    int data;

    Node(int data){
        this->next = NULL;
        this->data = data;
    }

};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
};


void insertAtPosition(Node* &tail, Node* &head, int position, int data){
    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    int cnt = 1;
    Node* temp = head;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}


int main(){
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head, 12);
    insertAtHead(head, 14);
    insertAtTail(tail, 8);
    insertAtPosition(tail, head, 1, 16);
    insertAtPosition(tail, head, 6, 6);
    print(head);
    return 0;
}