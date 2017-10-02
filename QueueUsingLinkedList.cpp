#include <iostream>
using namespace std;

struct node{
    node *next;
    int data;
};

class myQueue
{
    node *frontN,*rearN;

public:
    myQueue(){
        frontN = NULL;
        rearN = NULL;
    }

    void enqueue(int value){
        node *temp = new node;
        temp -> data = value;

        if(frontN == NULL  ){
            frontN = temp;
            rearN = temp;
            frontN -> next = NULL;
        }else{
            rearN -> next = temp;
            temp -> next = NULL;
            rearN = temp;
        }
        cout<<value<<" enqueued \n";
    }

    void dequeue(){
        if(frontN == NULL){
            cout<<"Already Empty Queue \n";
        }else if(frontN == rearN){
            cout<<frontN -> data<<" dequeued , now empty Queue \n";
             frontN = NULL;
             rearN = NULL;
        }else{
            cout<<frontN -> data<<" dequeued \n";
            frontN  = frontN -> next;
        }
    }

    void display(){
        node *temp = frontN;
        while(temp != rearN -> next){
                cout<<temp -> data<<"\t";
                temp = temp -> next;
        }
        cout<<endl;
    }

    void isEmpty(){
        if(frontN == NULL){
            cout<<"Queue is empty \n";
        }else{
            cout<<"Queue is not empty \n";
        }
    }
};
int main()
{
    myQueue q1;
    q1.enqueue(1);
    q1.display();
    q1.enqueue(10);
    q1.display();
    q1.enqueue(20);
    q1.display();
    q1.dequeue();
    q1.display();
    q1.isEmpty();
    return 0;
}
