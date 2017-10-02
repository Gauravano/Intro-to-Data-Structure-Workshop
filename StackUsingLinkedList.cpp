#include <iostream>

using namespace std;

struct node{
node *next;
int data;
};

class myStack{
    node *top;

    public:
    myStack(){
        top =  NULL;
    }

    void push(int value){
        node* temp = new node;
        temp -> data = value;

        if(top == NULL){
            top = temp;
            top -> next = NULL;
        }else{
            temp -> next = top;
            top = temp;
        }
        cout<<"Value Pushed \n";
    }

    void pop(){
        node *temp = new node;
        if(top == NULL){
            cout<<"Already Empty Stack "<<endl;
        }else{
            temp = top;
            top = top -> next;
            cout<<top -> data<<"popped out of Stack \n";
        }

    }

    void display(){
        node *temp = top;

        while(temp != NULL){
            cout<<temp -> data<<"\t";
            temp = temp -> next;
        }
        cout<<endl;
    }
};
int main()
{
    myStack s1;
    s1.push(12);
    s1.display();
    s1.push(13);
    s1.display();
    s1.push(14);
    s1.display();
    s1.pop();
    s1.display();
}
