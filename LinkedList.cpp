#include <iostream>

using namespace std;

struct node{

int data;   //integer data stored in each node
node *next; //address of next node in linked list
};
class list
{
    node *head , *tail;

    public:

    list(){
        cout<<"Constructor called"<<endl;
        head = NULL;
        tail = NULL;
    }

    void createNode(int value){
        node *temp = new node;
        temp -> data = value;
        temp -> next = NULL;

        if(head == NULL){
            head = temp;
            tail = temp;
            temp = NULL;
        }else{
            tail -> next = temp;
            tail = temp;
        }
        cout<<"Node Created \n";
    }

    void display(){
        node *temp = head;

        while(temp!= NULL){
                cout<<temp -> data<<"\t";
                temp = temp -> next;
        }
        cout<<endl;

    }

    void insert_start(int value){

        node *temp = new node;
        temp -> next = head;
        temp -> data = value;
        head = temp;
        cout<<"Data inserted at started"<<endl;
    }

    void insert_end(int value){
        node *temp = new node;
        temp -> data = value;
        temp -> next = NULL;
        tail -> next = temp;
        tail = temp;
        cout<<"Data inserted at end"<<endl;
    }
    void insert_position(int value,int position){
        node *temp = new node;
        temp -> data = value;
        node *prev = NULL;
        node *swipe = head;

        for(int i=1;i < position;i++){
            prev = swipe;
            swipe = swipe -> next;
        }
        prev -> next = temp;
        temp -> next = swipe;
        cout<<"Data Inserted at position "<<position;
        cout<<endl;
    }

    void delete_first(){
        node *temp = new node;
        temp = head;
        head = head -> next;
        delete(temp);
        cout<<"First Node Deleted "<<endl;
    }

    void delete_last(){
        node *temp = new node;
        node *current = head;
        node *prev = NULL;

        while (current -> next != NULL){
            prev = current;
            current = current -> next;
        }
        prev -> next = NULL;
        tail = prev;
        temp = current;
        delete(temp);
        cout<<"Last Node Deleted"<<endl;
    }

    void delete_particular(int position){
        node *temp = new node;
        node *current = head;
        node *prev = NULL;

        for(int i=1;i<position;i++){
            prev = current;
            current = current -> next;
        }
        temp = current;
        prev -> next = current -> next;
        delete(temp);
        cout<<"Node at position "<<position<<"deleted \n";
    }

};

int main()
{
    list a1;
    a1.createNode(23);
    a1.display();
    a1.insert_end(12);
    a1.display();
    a1.insert_end(34);
    a1.display();
    a1.insert_end(22);
    a1.display();
    a1.insert_position(10,2);
    a1.display();
    a1.delete_last();
    a1.display();
    return 0;
}
