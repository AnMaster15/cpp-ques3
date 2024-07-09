#include<iostream>
using namespace std;

class node{
    public:

    int data;
    node* next;
    node*prev;

    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

 void insert(node* &head,int data) {
    node* temp=new node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
       
    } 

    void positioninsertion(node* &head,int position,int data){
        if(position==1){
            insert(head,data);
            return;
        }

        node* temp=head;
        int cnt=1;

        while(cnt<position-1){
            temp=temp->next;
            cnt++;
        }
        

        node* insert=new node(data);

        insert->next=temp->next;
        temp->next->prev=insert;
        temp->next=insert;
        insert->prev=temp;


    }



void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" "<<endl;
          temp=temp->next;
    }
  
}


int main(){

    node*node1=new node(2);

    node* head=node1;
    // node* tail=node1;

    insert(head,4);
    positioninsertion(head,2,6);
    // insertattail(tail,5);

    print(head);



    return 0;
}