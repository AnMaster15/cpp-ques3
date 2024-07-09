#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next= NULL;
    }
        //destructor
        ~node(){
            int value=this->data;
            if(this->next !=NULL){
                delete next;
                this->next=NULL;//jo pointer purane wale node ko point kar raha tha use delte karne ke liye

            }
            cout<<"memory is free"<<endl;
        }
   

};

    void insertathead(node* &head,int d){
        node* temp=new node(d);

        temp->next=head;
        head=temp;

    }
    void insertattail(node* &tail,int data){
        node* temp=new node(data);

        tail->next=temp;
        tail=temp;
    }
    void insertatmiddle(node* &head,node* &tail,int position,int data){
        node* temp=head;
        int cnt=1;//pheli node
        if(position==1){
            insertathead(head,data);
            return;
        }

        while(cnt<position-1){
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL){
            insertattail(tail,data);
            return;
        }
        //creating a node for d

        node* nodetoinsert =new node(data);

        nodetoinsert->next=temp->next;
        temp->next =nodetoinsert;



    }

    void deletenode(node* &head,int position){
        if(position==1){     
           node* temp=head;
            head=head->next; 
                    //pheli
                    temp->next=NULL;
            delete temp;
        }
        else{                    //beech me aur end me
              node* curr =head;
              node* prev=NULL;
              int cnt=1;
              while(cnt < position){
                prev=curr;
                curr=curr->next;
                cnt++;
              }

              prev->next=curr->next;
              curr->next=NULL;
              delete curr;
        }
    }

    void print(node* &head){

        node*temp =head;

        while(temp !=NULL){
            cout<<temp->data<< " ";
            temp=temp->next;
        }

    }




int main(){

    node* node1=new node(2);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    node* head= node1;
     node* tail= node1;
    
    // print(head);

    insertattail(tail,12);

    // print(tail);

    insertatmiddle(head,tail,3,5);
    // print(head);

    deletenode(head,2);
    print(head);




    return 0;
}