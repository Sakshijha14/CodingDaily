#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data1,Node*next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=NULL;
    }
};

void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node*inserthead(Node*head,int val){
    
    Node* newNode=new Node(val);
    newNode->next=head;

    return newNode;
}

int main(){
    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);

    int data=0;
    
    Node*newhead=inserthead(head,data);
    print(newhead);

    return 0;
}

