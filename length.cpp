#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node*next;
    
    Node (int data1){
        data=data1;
        next=NULL;
    }
};

int lengthll(Node*head){

    Node*temp=head;
    int num=0;
    while(temp!=NULL){

        temp=temp->next;
        num++;
    }
    return num;
}

int main(){

    Node*head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);

    cout<<lengthll(head)<<endl;
}