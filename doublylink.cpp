#include<iostream>
using namespace std;



    class node{
        public:
        int data;
        node* prev;
        node* next;

        node(int data){
            this->data=data;
            this->prev=NULL;
            this->next=NULL;
            
        }

    };

     void insertathead(node* &head,int d){
        node* temp=new node(d);

        temp->next=head;
        head->prev=temp;
        head=temp;

    }
    void insertAtPosition(node* &head, int position, int d) {
    
  
    if(position == 1) {
        insertathead(head, d);
        return;
    }

    node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

   

    node* insert = new node(d);

    insert ->next = temp -> next;
    temp -> next -> prev = insert;
    temp -> next = insert;
    insert -> prev = temp;
}

void deleteNode(int position, node* & head) { 

   
    if(position == 1) {
        node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

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
        int display(node* &head,int value){
            node*temp=head;
            
            while(temp->next !=NULL){
                {
            if (temp->data == value)
            
            temp = temp->next;            }
            return 1;
}

                
                


            }



        

    
    int main(){

        node* node1=new node(4);

        node* head=node1;

        insertathead(head,5);

        insertAtPosition(head,2,6);

        // deleteNode(1,head);

        print(head);

        // if(display(head,6)==true){
        //     cout<<"found"<<endl;

        // }
        // else{
        //     cout<<"not found"<<endl;
        // }

        int ans=display(head,2);
        cout<<ans;





    return 0;
}
























































// ~node(){
//             int val = this -> data;
//         if(next != NULL) {
//             delete next;
//             next = NULL;
//             prev=NULL;
//         }
//         cout << "memory free for node with data "<< val << endl;
//     }
