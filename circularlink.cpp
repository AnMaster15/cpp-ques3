#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~node(){
        int value=this->data;
            if(this->next !=NULL){
                delete next;
                this->next=NULL;//jo pointer purane wale node ko point kar raha tha use delte karne ke liye

            }
            cout<<"memory is free"<<endl;
    }
    };


    void insertnode(node* &tail,int element,int data){
        //assuming element is present in link list

        if(tail==NULL){ //empty
            node* newnode=new node(data);
            tail=newnode;
            tail->next=tail;
        }
        else{

            node* curr=tail;

            while(curr->data !=element){
                curr=curr->next;
            }

            node* temp=new node(data);
            temp->next=curr->next;
            curr->next=temp;

        }

    }
    void print(node* tail){{
        node* temp=tail;

        do{
              cout<<tail->data<<" ";
            tail=tail->next;

        }while(tail->next !=temp);
          
        
    }
    cout<<endl;

    }
    void deletion(node* tail,int element){
        
        if(tail==NULL){
            cout<<"list is empty"<<endl;       
            return; 

    }
    else{

        node* prev =tail;
        node* curr=prev->next;

        while(curr->data !=element){
            prev=curr;
            curr=curr->next;

        }

        prev->next=curr->next;
        if (tail==curr)
        {
          tail=curr;
        }
        if(curr==prev){
            tail=NULL;
        }
        
        curr->next=NULL;
        delete curr;

    }
    }



int main(){
    node* tail=NULL;
    // insertnode(tail,5,3);
    

insertnode(tail,3,5);
insertnode(tail,5,7);
insertnode(tail,7,9);
// print(tail);

insertnode(tail,9,9);
print(tail);

deletion(tail,7);
print(tail);

    return 0;
}